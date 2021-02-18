/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:07:24 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/05 18:46:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_define.h"
#include "libft_str.h"
#include "libft_num.h"
#include "libft_conv.h"

/*
** This function gets each digit
*/

static int64_t	digit_to_char(int64_t n, int base)
{
	int64_t		rem;

	rem = n % base;
	if (rem < DEC_BASE)
		return (rem + '0');
	return (rem - DEC_BASE + 'a');
}

/*
** This function checks whether n is negative
*/

static bool		ft_is_neg(int n, int64_t *nbr, size_t *sign)
{
	*sign = 0;
	*nbr = n;
	if (n < 0)
	{
		*sign = 1;
		*nbr *= -1;
		return (true);
	}
	return (false);
}

/*
** This function converts an integer to a string representation using
** the specified base
**
** n: An integer
** output: The string representation
** base: An integer (2 to 16)
**
** returns: The converted number as a string representation
**          NULL otherwise
*/

char			*ft_itoa(int n, char *output, int base)
{
	int64_t		nbr;
	size_t		nbr_len;
	size_t		sign;
	bool		is_neg;

	if ((base < BINARY_BASE) || (base > HEX_BASE))
		return (NULL);
	if (n == 0)
		output = ft_strdup("0");
	else
	{
		is_neg = ft_is_neg(n, &nbr, &sign);
		nbr_len = ft_nbrlen_base(n, base);
		output = ft_strnew(nbr_len);
		if (!output)
			return (NULL);
		if (is_neg && base == DEC_BASE)
			output[0] = MINUS;
		while (nbr_len-- > sign)
		{
			output[nbr_len] = digit_to_char(nbr, base);
			nbr /= base;
		}
	}
	return (output);
}
