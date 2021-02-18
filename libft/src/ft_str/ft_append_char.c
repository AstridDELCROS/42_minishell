/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:29:54 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 23:05:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"

/*
** This function appends the character c to the string s
**
** s: A string
** c: A character
**
** returns: The new string
**          NULL otherwise
*/

char		*ft_append_char(char *s, char *c, bool replace)
{
	char	*result;
	size_t	len;

	len = 0;
	if (s)
		len = ft_strlen(s);
	result = ft_strnew(len + 1);
	if (!result)
		return (NULL);
	if (s)
	{
		ft_strlcpy(result, s, (len + 1));
		if (replace)
			ft_strdel(&s);
	}
	ft_strlcpy(result + len, c, 2);
	return (result);
}
