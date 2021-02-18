/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 23:20:53 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:51:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/*
** Function: Outputs the padding to the standard output
**
** pad: The pad character (either space or 0)
** len: The size of the output string
** spec: A structure containing the retrieved formatting data
**
** returns: The count of printed characters
*/

int			ft_put_padding(int pad, int len, t_spec *spec)
{
	int		printed;

	printed = 0;
	while (spec->width-- > len)
		printed += write(spec->dst_fd, &pad, 1);
	return (printed);
}
