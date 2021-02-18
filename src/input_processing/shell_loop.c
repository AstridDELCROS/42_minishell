/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:02:51 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 03:35:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_utils.h"
#include "sh_input_processing.h"

/*
** While the shell is not 'done', processes the user input: a command
**   Prompt the user for and input
**   Parse the command
**   Execute the command
**   Return status
*/

int			shell_loop(t_shctrl *ft_sh)
{
	while (!g_done)
		process_input(ft_sh);
	free_all(ft_sh);
	return (g_status);
}
