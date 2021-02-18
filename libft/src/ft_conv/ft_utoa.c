/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 18:44:40 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/05 15:54:46 by mboivin          ###   ########.fr       */
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
** This function converts an unsigned integer to a string representation using
** the specified base
**
** n: An integer
** output: The string representation
** base: An integer (2 to 16)
**
** returns: The converted number as a string representation
**          NULL otherwise
*/

char			*ft_utoa(int64_t n, char *output, int base)
{
	int64_t		nbr;
	size_t		n_len;

	if ((base < BINARY_BASE) || (base > HEX_BASE))
		return (NULL);
	if (n == 0)
		output = ft_strdup("0");
	else
	{
		nbr = n;
		if (n < 0)
			nbr *= -1;
		n_len = ft_unbrlen_base(nbr, base);
		output = ft_strnew(n_len);
		if (!output)
			return (NULL);
		while (nbr != 0 && n_len-- > 0)
		{
			output[n_len] = digit_to_char(nbr, base);
			nbr /= base;
		}
	}
	return (output);
}
