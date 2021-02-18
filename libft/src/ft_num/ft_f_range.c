/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:59:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:46:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num.h"

/*
** This function checks whether a double is in a given range
**
** x: A number
** start: Range start
** end: Range end
**
** returns: A non-zero integer if x is in the range
**          0 otherwise
*/

bool	ft_f_range(double x, double start, double end)
{
	return (start <= x && x <= end);
}
