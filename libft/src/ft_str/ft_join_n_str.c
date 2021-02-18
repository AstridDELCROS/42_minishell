/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_n_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:25:33 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 21:53:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft_str.h"

/*
** This function allocates (with malloc(3)) and returns a new string, result of
** the concatenation of n strings
**
** count: The number of strings to join
**
** returns: The new string
**          NULL otherwise
*/

char		*ft_join_n_str(int count, ...)
{
	va_list	ap;
	char	*result;

	if (count == 0)
		return (NULL);
	result = NULL;
	va_start(ap, count);
	while (count > 0)
	{
		result = ft_strjoindelone(result, va_arg(ap, char *));
		count--;
	}
	va_end(ap);
	return (result);
}
