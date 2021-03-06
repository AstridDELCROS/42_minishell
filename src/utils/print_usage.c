/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:50:46 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/18 18:42:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_utils.h"

/*
** This function prints the usage message
*/

void	print_usage(void)
{
	ft_dprintf(STDERR_FILENO, "Usage: ./minishell\n");
	exit(EXIT_SUCCESS);
}
