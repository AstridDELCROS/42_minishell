/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 16:12:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				main(int argc, char **argv, char **envp)
{
	t_shctrl	ft_sh;

	(void)argv;
	/* Si argc != 1, on affiche le message d'usage car minishell ne prend aucun arg */
	if (argc != NO_ARGS)
		print_usage();
	/* On récupère l'env et on set quelques variables */
	start_shell(envp);
	/* cf. commentaire ci-dessous */
	create_shell(&ft_sh);
	/* Boucle qui attend l'input utilisateur */
	return (shell_loop(&ft_sh));
}

/*
** Fichier src/subsystems/sh_ctrl.c
**
** On init les éléments du shell à NULL
**
** void	create_shell(t_shctrl *ft_sh)
** {
** 	ft_sh->lexer = NULL;
** 	ft_sh->ast = NULL;
** 	ft_sh->cmd = NULL;
** }
*/
