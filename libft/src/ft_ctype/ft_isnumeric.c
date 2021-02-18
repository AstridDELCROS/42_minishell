/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 00:23:51 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 19:27:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_define.h"
#include "libft_ctype.h"

/*
** This function checks if a string is a numeric value
**
** s: A string representation of a number
**
** returns: A non-zero integer if s is a numeric value
**          0 otherwise
*/

int			ft_isnumeric(char *s)
{
	size_t	i;
	int		retval;

	i = 0;
	retval = 0;
	if ((s[i] == PLUS) || (s[i] == MINUS))
		i++;
	while (s[i])
	{
		if (!(retval = ft_isdigit(s[i])))
			break ;
		i++;
	}
	return (retval);
}
