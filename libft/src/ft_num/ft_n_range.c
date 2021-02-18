/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:59:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:47:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num.h"

/*
** This function checks whether an integer is in a given range
**
** x: A number
** start: Range start
** end: Range end
**
** returns: A non-zero integer if x is in the range
**          0 otherwise
*/

bool	ft_n_range(int x, int start, int end)
{
	return (start <= x && x <= end);
}
