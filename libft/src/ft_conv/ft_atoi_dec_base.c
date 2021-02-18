/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_dec_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:21:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/01 20:43:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_define.h"
#include "libft_ctype.h"
#include "libft_conv.h"

/*
** This function converts c to int
*/

static int		char_to_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (c - ZERO);
	else if (c >= 'a' && c <= 'f')
		return (c + DEC_BASE - 'a');
	else if (c >= 'A' && c <= 'F')
		return (c + DEC_BASE - 'A');
	return (0);
}

/*
** This function checks if c is present in base
**
** c: A character
** base: The given base
**
** returns: true if c is present in base
**          false otherwise
*/

static bool		is_in_base(int c, int base)
{
	const char	*lower_hex = "0123456789abcdef";
	int			i;

	i = 0;
	while (i < base)
	{
		if ((lower_hex[i] == ft_tolower(c)))
			return (true);
		i++;
	}
	return (false);
}

/*
** This function converts a string to a base 10 integer
**
** s: A string representation of a number
** from_base: Base of s (2 to 16)
**
** returns: The converted number as an int value
**          0 otherwise
*/

int				ft_atoi_dec_base(const char *s, int from_base)
{
	int			result;
	int			sign;

	if ((from_base < BINARY_BASE) || (from_base > HEX_BASE))
		return (0);
	result = 0;
	sign = 1;
	while (*s && ft_isspace(*s))
		s++;
	if (*s == MINUS)
		sign = -1;
	if ((*s == PLUS) || (*s == MINUS))
		s++;
	while (*s && is_in_base(*s, from_base))
		result = (result * from_base) + char_to_digit(*(s++));
	return (sign * result);
}
