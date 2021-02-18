/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:20:15 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 16:25:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_execution.h"
#include "sh_input_processing.h"

/*
** This function processes the command input
*/

void		process_input(t_shctrl *ft_sh)
{
	int		ret;

	ret = get_command(ft_sh);
	/* Si pas d'erreur lors de la récupération de la commande (input utilisateur), lexing (split tokens) ou parsing */
	if (ret != FAIL_RET)
	/* On traverse l'arbre pour créer une table de commandes et l'exécuter */
		traverse_tree(ft_sh, ft_sh->ast);
	destroy_shell(ft_sh);
}
