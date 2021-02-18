/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:22:09 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 14:31:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctype.h"

/*
** Recoded isascii libc function: Checks if c is a 7-bit US-ASCII character
** code between 0 and octal 0177 inclusive
**
** c: A character
**
** returns: A non-zero integer if c is an ASCII character
**          0 otherwise
*/

int		ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
