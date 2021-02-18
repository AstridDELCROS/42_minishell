/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 21:18:36 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:51:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/*
** Function: Retrieves the corresponding argument to fill a specifier field
**
** ap: A pointer to the list of arguments
**
** returns: The argument
*/

int			get_arg(va_list ap)
{
	int		field;

	field = va_arg(ap, int);
	return (field);
}
