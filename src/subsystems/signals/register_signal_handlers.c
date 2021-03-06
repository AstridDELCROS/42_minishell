/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_signal_handlers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:51:19 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 12:37:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function registers signal handlers
** SIGINT is handled
** SIGQUIT is ignored
** SIGUSR1 is used to signal the program exits and needs cleanup
*/

static void	handle_sig_err(void)
{
	ft_clearenv();
	g_status = EXIT_FAILURE;
	exit(g_status);
}

void		register_signal_handlers(void)
{
	if (
		(signal(SIGINT, handle_fatal_error) == SIG_ERR)
		|| (signal(SIGQUIT, SIG_IGN) == SIG_ERR))
		handle_sig_err();
}
