/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 13:19:02 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:49:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/*
** Function: Handles type c and outputs s to the standard output
**
** s: A string representation of the formatted input
** spec: A structure containing the retrieved formatting data
**
** returns: The count of printed characters
*/

static int	ft_printf_char(char *s, t_spec *spec)
{
	int		printed;
	int		pad;

	printed = 0;
	pad = SPACE;
	if (!(spec->flag & LEFTALIGN) && spec->width > 1)
	{
		if (s[0] == PERCENT && spec->flag & ZERO_PAD)
			pad = ZERO;
		printed += ft_put_padding(pad, 1, spec);
	}
	printed += write(spec->dst_fd, s, 1);
	if (spec->flag & LEFTALIGN && spec->width > 1)
		printed += ft_put_padding(pad, 1, spec);
	return (printed);
}

/*
** Function: Handles type c
**
** spec: A structure containing the retrieved formatting data
** ap: A pointer to the list of arguments
**
** returns: The count of printed characters
*/

int			ft_handle_char(t_spec *spec, va_list ap)
{
	int		printed;
	char	c;
	char	*buffer;

	c = va_arg(ap, int);
	if (spec->modifier == 'l')
		buffer = ft_atos((wchar_t)c);
	else
		buffer = ft_atos(c);
	if (!buffer)
		return (-1);
	printed = ft_printf_char(buffer, spec);
	free(buffer);
	return (printed);
}

/*
** Function: Handles percent character
**
** spec: A structure containing the retrieved formatting data
** ap: A pointer to the list of arguments
**
** returns: The count of printed characters
*/

int			ft_handle_percent(t_spec *spec, va_list ap)
{
	int		printed;
	char	*buffer;

	(void)ap;
	buffer = ft_strdup("%");
	if (!buffer)
		return (-1);
	printed = ft_printf_char(buffer, spec);
	free(buffer);
	return (printed);
}
