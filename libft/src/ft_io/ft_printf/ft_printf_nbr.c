/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 13:19:53 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/31 02:39:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/*
** Function: Handles numbers and outputs s to the standard output
**
** pad: The pad character (either space or 0)
** len: The size of the output string
** s: A string representation of the formatted input
** spec: A structure containing the retrieved formatting data
**
** returns: The count of printed characters
*/

static int	ft_printf_int(char *s, int pad, int len, t_spec *spec)
{
	int		printed;
	int		zeroes;

	printed = 0;
	zeroes = ft_strlen(s);
	if (spec->prec >= (int)ft_strlen(s) && ft_is_prefix(s[0]))
	{
		spec->width--;
		zeroes--;
	}
	if (spec->flag & ZERO_PAD && spec->prec == -1 && ft_is_prefix(s[0]))
		printed += write(spec->dst_fd, s++, 1);
	if (!(spec->flag & LEFTALIGN) && spec->width > (int)ft_strlen(s))
		printed += ft_put_padding(pad, len, spec);
	if (spec->prec >= (int)ft_strlen(s))
	{
		if (ft_is_prefix(s[0]))
			printed += write(spec->dst_fd, s++, 1);
		printed += ft_put_zeroes(zeroes, spec);
	}
	printed += write(spec->dst_fd, s, ft_strlen(s));
	if (spec->flag & LEFTALIGN && spec->width > (int)ft_strlen(s))
		printed += ft_put_padding(pad, len, spec);
	return (printed);
}

/*
** Function: Handles zero with precision 0 and outputs s to the standard output
**
** s: A string representation of the formatted input
** spec: A structure containing the retrieved formatting data
**
** returns: The count of printed characters
*/

static int	ft_printf_zero(char *s, t_spec *spec)
{
	int		printed;
	int		len;

	printed = 0;
	len = 0;
	if (ft_is_prefix(s[0]))
		spec->width--;
	if (!(spec->flag & LEFTALIGN) && spec->width >= (int)ft_strlen(s))
		printed += ft_put_padding(SPACE, len, spec);
	if (ft_is_prefix(s[0]))
		printed += write(spec->dst_fd, s, 1);
	if (spec->flag & LEFTALIGN && spec->width >= (int)ft_strlen(s))
		printed += ft_put_padding(SPACE, len, spec);
	return (printed);
}

/*
** Function: Handles types diouxX to outputs s
**
** s: A string representation of the formatted input
** spec: A structure containing the retrieved formatting data
** arg: The int argument
**
** returns: The count of printed characters
*/

int			ft_printf_nbr(char *s, t_spec *spec, int arg)
{
	int		printed;
	int		len;
	int		pad;

	printed = 0;
	if (spec->prec >= (int)ft_strlen(s))
		len = spec->prec;
	else
		len = (int)ft_strlen(s);
	if (spec->flag & ZERO_PAD && spec->prec == -1 && !(spec->flag & LEFTALIGN))
		pad = ZERO;
	else
		pad = SPACE;
	if (spec->prec == 0 && arg == 0)
		printed += ft_printf_zero(s, spec);
	else
		printed += ft_printf_int(s, pad, len, spec);
	return (printed);
}
