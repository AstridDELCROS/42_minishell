/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_seq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 16:01:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function checks whether the current simple command is the last one
*/

static bool		is_last_command(t_cmd *cmd)
{
	return (cmd->curr_cmd == (cmd->cmd_count - 1));
}

/*
** This function checks whether a process is a child process
*/

static bool		is_child_process(pid_t pid)
{
	/* Le PID d'un child process est égal à 0 */
	return (pid == 0);
}

/*
** This function creates a pipe object
**
** pdf contient 2 fd:
** READ_END: entrée où on lit
** WRITE_END: sortie où on écrit
*/

static void		create_pipe(t_shctrl *ft_sh, t_streams *redir)
{
	int	pfd[2];

	if (pipe(pfd) == FAIL_RET)
	{
		/* Si la création du pipe ne marche pas, on imprime l'erreur */
		print_errno("pipe");
		/* On retourne 1 et on exit */
		g_status = EXIT_FAILURE;
		exit_shell(ft_sh);
	}
	redir->in = pfd[READ_END];
	redir->out = pfd[WRITE_END];
}

/*
** Each command in a pipeline is executed in its own subshell, which is a
** separate child process
*/

static void		exec_in_subshell(t_shctrl *ft_sh, t_simplecmd *simple_cmd)
{
	exec_simple_cmd(simple_cmd);
	/* Il faut exit le child process à la fin */
	exit_shell(ft_sh);
}

/*
** This function executes a pipe sequence
**
** The output of each command in the pipeline is connected via a pipe to the
** input of the next command. That is, each command reads the previous
** command’s output. This connection is performed before any redirections
** specified by the command.
*/

void			exec_pipe_seq(t_shctrl *ft_sh, t_cmd *cmd)
{
	pid_t		pid;
	t_streams	backup;
	t_streams	redir;
	int			wstatus;

	pid = -1;
	wstatus = -1;
	/* On duplique stdin et stdout en backup */
	dup_streams(&backup);
	/* La première commande recevra stdin */
	redir.in = dup(backup.in);
	while (cmd->curr_cmd < cmd->cmd_count)
	{
		/* L'entrée du pipe reçoit stdin */
		redirect_stream(redir.in, STDIN_FILENO);
		/* La sortie du pipe pointe sur stdout */
		redir.out = dup(backup.out);
		/* Tant que ce n'est pas la dernière commande de la command table, on créé un pipe */
		if (!is_last_command(cmd))
			create_pipe(ft_sh, &redir);
		/* La sortie du pipe reçoit stdout */
		redirect_stream(redir.out, STDOUT_FILENO);
		/* On créé unchild process qui reçoit les fd ouverts */
		spawn_process(ft_sh, &pid);
		/* Si c'est le child process, on exécute la commande */
		if (is_child_process(pid))
			exec_in_subshell(ft_sh, cmd->simple_cmds[cmd->curr_cmd]);
		/* On incrémente afin de passer à la commande suivante */
		cmd->curr_cmd++;
	}
	/* On restore stdin et stdout grâce au backup */
	restore_default_streams(backup);
	/* On attend que le child process se termine */
	waitpid(pid, &wstatus, DEFAULT_VALUE);
	/* Si le child process s'est terminé sans pbm (WIFEXITED retourne true) */
	if (WIFEXITED(wstatus))
		/* On récupère son code de retour */
		g_status = WEXITSTATUS(wstatus);
}
