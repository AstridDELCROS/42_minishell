/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 21:40:54 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 16:40:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** Function: Frees an array of strings
**
** to_free: The array of strings to be freed
*/

void	ft_str_arr_del(char **to_free)
{
	int	i;

	i = 0;
	while (to_free && to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	if (to_free)
		free(to_free);
}
