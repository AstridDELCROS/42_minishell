/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:25:22 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 16:07:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function spawns a new process to execute a simple command
*/

void	spawn_process(t_shctrl *ft_sh, pid_t *pid)
{
	if ((*pid = fork()) == FAIL_RET)
	{
		/* Si la création du child process ne marche pas, on imprime l'erreur */
		print_errno("fork");
		/* On retourne 1 et on exit */
		g_status = EXIT_FAILURE;
		exit_shell(ft_sh);
	}
}
