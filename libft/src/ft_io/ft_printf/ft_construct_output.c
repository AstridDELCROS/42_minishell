/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 12:33:13 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:48:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/*
** Function: Constructs the output by stopping at each percent character
** or prints directly to screen
**
** format: The formatting string
** ap: A pointer to the first optional argument in the list of arguments
**
** returns: The count of printed characters
*/

int			ft_construct_output(int fd, const char *format, va_list ap)
{
	int		printed;

	if (!format)
		return (0);
	printed = 0;
	while (*format)
	{
		if (*format == PERCENT)
		{
			format++;
			printed += ft_parse_format(fd, &format, ap);
		}
		else
		{
			printed += write(fd, format, 1);
			format++;
		}
	}
	return (printed);
}
