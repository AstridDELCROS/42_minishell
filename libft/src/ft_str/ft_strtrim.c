/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:43:57 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/09 17:54:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctype.h"
#include "libft_str.h"

/*
** This function allocates (with malloc(3)) and returns a copy of the string
** given as argument without the characters specified in the set argument at the
** beginning and the end of the string
**
** s: The string to be trimmed
** set: The reference set of characters to trim
**
** returns: The trimmed string
**          NULL otherwise
*/

char		*ft_strtrim(const char *s, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*result;

	if (!s || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && ft_ischarset(s[start], set))
		start++;
	if (!s[start])
		return (ft_strdup(""));
	while (s[end] && ft_ischarset(s[end], set))
		end--;
	len = (end - start) + 1;
	result = ft_substr(s, start, len);
	return (result);
}
