/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 23:29:02 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 20:21:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** This function allocates a new string, result of the concatenation of prefix
** and s
**
** prefix: A pointer to the prefix
** s: A pointer to the string
**
** returns: The new string
**          NULL otherwise
*/

char		*ft_strprepend(const char *prefix, char *s)
{
	char	*result;
	size_t	len_prefix;
	size_t	len_s;
	size_t	len;

	if (!prefix || !s)
		return (NULL);
	len_prefix = ft_strlen(prefix);
	len_s = ft_strlen(s);
	len = len_prefix + len_s;
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, prefix, (len_prefix + 1));
	ft_strlcpy(result + len_prefix, s, (len_s + 1));
	ft_strdel(&s);
	return (result);
}
