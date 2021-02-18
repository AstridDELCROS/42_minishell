/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 13:19:02 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/08 19:39:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/*
** Function: Handles type s and outputs s to the standard output
**
** s: A string representation of the formatted input
** spec: A structure containing the retrieved formatting data
**
** returns: The count of printed characters
*/

static int	ft_printf_str(char *s, t_spec *spec)
{
	int		printed;
	int		len;
	int		pad;

	printed = 0;
	len = ft_strlen(s);
	pad = SPACE;
	if (!(spec->flag & LEFTALIGN) && spec->width > (int)ft_strlen(s))
	{
		if (spec->flag & ZERO_PAD)
			pad = ZERO;
		printed += ft_put_padding(pad, len, spec);
	}
	printed += write(spec->dst_fd, s, len);
	if (spec->flag & LEFTALIGN && spec->width > (int)ft_strlen(s))
		printed += ft_put_padding(SPACE, len, spec);
	return (printed);
}

/*
** Function: Handles wide characters using the specified length
**
** arg: The argument to convert
**
** returns: A string representation of the wide character
*/

static char	*length_wchar(wchar_t *arg)
{
	char	*result;
	char	*tmp;

	result = ft_strnew(1);
	if (!result)
		return (NULL);
	while (*arg)
	{
		tmp = (ft_atos(*arg));
		result = ft_strjoindel(result, tmp);
		arg++;
	}
	return (result);
}

/*
** Function: Handles type s
**
** spec: A structure containing the retrieved formatting data
** ap: A pointer to the list of arguments
**
** returns: The count of printed characters
*/

static char	*ft_strshorten(char *src, int size)
{
	char	*result;
	int		i;

	if (!src || (size < 0))
		return (NULL);
	i = 0;
	result = ft_strnew(size);
	if (!result)
		return (NULL);
	while (src[i] && (i < size))
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	ft_strdel(&src);
	return (result);
}

int			ft_handle_str(t_spec *spec, va_list ap)
{
	int		printed;
	char	*arg;
	char	*buffer;

	arg = va_arg(ap, char *);
	if (!arg)
		buffer = ft_strdup("(null)");
	else if (spec->modifier == 'l')
		buffer = length_wchar((wchar_t *)arg);
	else
		buffer = ft_strdup(arg);
	if (spec->prec >= 0 && spec->prec < (int)ft_strlen(buffer))
		buffer = ft_strshorten(buffer, spec->prec);
	if (!buffer)
		return (-1);
	printed = ft_printf_str(buffer, spec);
	free(buffer);
	return (printed);
}
