/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:24:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 20:18:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** Recoded strnstr libc function: Locates the first occurrence of the
** null-terminated string needle in the null-terminated string haystack
**
** s1, s2: Pointers to the buffers to be compared
** n: The number of bytes to be compared
**
** returns: If needle is an empty string, haystack is returned
**          If needle occurs nowhere in haystack, NULL is returned
**          Otherwise a pointer to the first character of the first occurrence
**          is returned
*/

char		*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	needle_len;
	char	*from;
	char	*to_find;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	from = (char *)haystack;
	to_find = (char *)needle;
	while (from[i] && ((i + needle_len) <= n))
	{
		if (ft_strnequ(from + i, to_find, needle_len))
			return ((char *)(from + i));
		i++;
	}
	return (NULL);
}
