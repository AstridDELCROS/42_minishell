/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:23:59 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 03:25:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** This function swaps the value of two strings
*/

void		ft_strswap(char **a, char **b)
{
	char	*tmp;

	if (!(*a) || !(*b))
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
