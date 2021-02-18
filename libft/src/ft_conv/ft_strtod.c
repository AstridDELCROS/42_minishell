/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:21:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 21:35:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_define.h"
#include "libft_ctype.h"
#include "libft_str.h"
#include "libft_conv.h"

/*
** This function returns the decimal part
*/

static double	decimal_val(const char *s, char **endptr)
{
	int			i;
	double		result;
	double		val;

	i = 0;
	result = 0.0;
	val = 0.1;
	while (s[i] && ft_isdigit(s[i]))
	{
		result = result + (s[i] - ZERO) * val;
		val /= DEC_BASE;
		i++;
	}
	*endptr = ft_strdup(s);
	return (result);
}

/*
** Recoded strtod libc function: Converts a string to a double
**
** s: The reference to an already allocated object of type char*, whose value is
** set by the function to the next character in s after the numerical value
**
** returns: The converted integral number as an int value
**          0 otherwise
*/

double			ft_strtod(const char *s, char **endptr)
{
	int			i;
	double		result;
	int			sign;

	i = 0;
	result = 0.0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == MINUS && ft_isdigit(s[i + 1]))
		sign = -1;
	if ((s[i] == PLUS) || (s[i] == MINUS))
		i++;
	while (s[i] && ft_isdigit(s[i]))
	{
		result = (result * DEC_BASE) + (s[i] - ZERO);
		i++;
	}
	if (s[i++] == DOT)
		result = result + decimal_val(s + i, endptr);
	else
		*endptr = ft_strdup(s);
	return ((double)sign * result);
}
