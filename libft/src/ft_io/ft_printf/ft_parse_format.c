/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 12:33:13 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:50:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/*
** Array of structures: pointers to conversion functions matching types
*/

static t_conv	g_conv[] =
{
	{ 'c', &ft_handle_char },
	{ 's', &ft_handle_str },
	{ 'p', &ft_handle_ptr },
	{ 'd', &ft_handle_int },
	{ 'i', &ft_handle_int },
	{ 'o', &ft_handle_oct },
	{ 'u', &ft_handle_uint },
	{ 'x', &ft_handle_hex },
	{ 'X', &ft_handle_hex },
	{ '%', &ft_handle_percent }
};

/*
** Function: Finds the conv function matching type
**
** spec: A structure containing the retrieved formatting data
** ap: A pointer to the list of arguments
**
** returns: A pointer to the required conv function
*/

static int	format_output(t_spec *spec, va_list ap)
{
	int		i;

	i = 0;
	while (g_conv[i].type != spec->type)
		i++;
	return ((*g_conv[i].func)(spec, ap));
}

/*
** Function: Inits the spec data structure
*/

static void	create_spec(int fd, t_spec *spec)
{
	spec->flag = 0;
	spec->prec = -1;
	spec->width = 0;
	spec->modifier = 0;
	spec->type = '\0';
	spec->dst_fd = fd;
}

/*
** Function: Parses the formatting string and fill the spec data structure
**
** format: The formatting string
** ap: A pointer to the list of arguments
**
** returns: The count of printed characters
*/

int			ft_parse_format(int fd, const char **format, va_list ap)
{
	t_spec	spec;

	create_spec(fd, &spec);
	get_flags(format, &spec);
	get_width(format, &spec, ap);
	get_precision(format, &spec, ap);
	get_length(format, &spec);
	get_type(format, **format, &spec);
	if (spec.type != '\0')
		return (format_output(&spec, ap));
	return (0);
}
