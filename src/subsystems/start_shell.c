/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:11:11 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 16:14:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "libft_mem.h"
#include "sh_env.h"
#include "sh_subsystems.h"

volatile sig_atomic_t	g_status;
volatile sig_atomic_t	g_done;
volatile sig_atomic_t	g_char_dev;

/*
** Shell startup
** This function loads environment, sets flags and registers signal handlers
**
** envp: The environment represented as an array of strings
*/

void	start_shell(char **envp)
{
	/* Si pas d'environnement, on set juste PWD, SHLVL et SHELL (toujours SHELL=/bin/bash puisqu'on imite bash) */
	if (!(*envp))
	{
		g_env = ft_calloc(DEFAULT_ENV, sizeof(char *));
		if (!g_env)
			return ;
		set_working_dir();
		ft_putenv(DEFAULT_SHLVL);
		ft_putenv(DEFAULT_SHELL);
	}
	/* Sinon, on récupère l'environnement grâce à envp */
	else
		load_environment(envp);
	/* Le status est par défaut à 0 au départ */
	g_status = EXIT_SUCCESS;
	/* Le programme n'est pas terminé */
	g_done = false;
	/* Aucune char device (/dev/random ou /dev/zero) n'est ouverte */
	g_char_dev = false;
	/* On enregistre les signal handlers */
	register_signal_handlers();
}
