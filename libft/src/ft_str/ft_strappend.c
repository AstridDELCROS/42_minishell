/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 23:29:02 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 20:19:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** This function allocates a new string, result of the concatenation of s and
** suffix
**
** s: A pointer to the string
** suffix: A pointer to the suffix
**
** returns: The new string
**          NULL otherwise
*/

char		*ft_strappend(char *s, char *suffix)
{
	char	*result;
	size_t	len_s;
	size_t	len_suffix;
	size_t	len;

	if (!s || !suffix)
		return (NULL);
	len_s = ft_strlen(s);
	len_suffix = ft_strlen(suffix);
	len = len_suffix + len_s;
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, (len_s + 1));
	ft_strlcpy(result + len_s, suffix, (len_s + 1));
	ft_strdel(&s);
	return (result);
}
