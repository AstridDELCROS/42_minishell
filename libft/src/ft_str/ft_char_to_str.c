/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 15:42:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/12 15:43:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"

/*
** This function appends the char c to the string s
**
** s: A string
** c: The character to append
**
** returns: The resulting string
**          NULL otherwise
*/

char		*ft_char_to_str(char *s, char c)
{
	char	*result;
	size_t	len;

	result = NULL;
	len = 0;
	if (s)
		len = ft_strlen(s);
	result = ft_strnew(len + 1);
	if (!result)
		return (NULL);
	if (s)
	{
		ft_strlcpy(result, s, (len + 1));
		ft_strdel(&s);
	}
	ft_strlcpy(result + len, &c, 2);
	return (result);
}
