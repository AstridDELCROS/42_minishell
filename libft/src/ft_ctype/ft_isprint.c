/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:22:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 14:35:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctype.h"

/*
** Recoded isprint libc function: Checks if c is a printable character
**
** c: A character
**
** returns: A non-zero integer if c is a printable character
**          0 otherwise
*/

int		ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
