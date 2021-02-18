/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 16:06:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function invokes a shell builtin
*/

void			invoke_builtin(t_simplecmd *builtin)
{
	if (builtin->cmd_path)
		g_status = (*builtin->builtin_func)(builtin->argc, builtin->cmd_args);
}

/*
** This function executes a simple command
*/

void			exec_simple_cmd(t_simplecmd *simple_cmd)
{
	t_streams	backup;

	/* S'il y a des redirection, on redirige les input/output */
	handle_redirection(simple_cmd, &backup);
	/* S'il y a une commande (il peut y avoir une redir sans commande) */
	if (simple_cmd->cmd_path)
	{
		/* Si c'est une builtin, on utilise cette fonction */
		if (is_builtin(simple_cmd))
			invoke_builtin(simple_cmd);
		/* Sinon, on utilise execve */
		else
		{
			/* Si execve est successful, il retourne sans passer à la ligne suivante */
			execve(simple_cmd->cmd_path, simple_cmd->cmd_args, g_env);
			/* Sinon, il affiche le message d'erreur */
			print_errno(simple_cmd->cmd_args[CMD_NAME]);
		}
	}
	/* On restore stdin et stdout en cas de redirection */
	/* S'il n'y a pas de redirection, ça ne fait rien (condition dans la fonction) */
	restore_default_streams(backup);
}

/*
** This function executes all simple commands
** When a simple command other than a builtin is to be executed, it is invoked
** in a child process
*/

void			execute(t_shctrl *ft_sh, t_cmd *cmd)
{
	/* Si aucune commande dans la command table, on annule l'exécution */
	if (cmd->cmd_count == DEFAULT_VALUE)
		return ;
	/* Si 1 seule command et builtin, on la lance sans child process */
	if (cmd->cmd_count == 1 && is_builtin(cmd->simple_cmds[cmd->curr_cmd]))
		exec_simple_cmd(cmd->simple_cmds[cmd->curr_cmd]);
	/* Sinon, on lance la ou les commandes dans un child process chacune */
	else
		exec_pipe_seq(ft_sh, cmd);
}
