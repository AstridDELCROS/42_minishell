/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:38:42 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/31 03:33:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"

/*
** This function computes the number of strings to split
**
** s: The total string to be split
** delim: The delimiter character
**
** returns: The number of substrings delimited by c
*/

static size_t	ft_count_strings(const char *s, char delim)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != delim) && ((i == 0) || (s[i - 1] == delim)))
			count++;
		i++;
	}
	return (count);
}

/*
** This function allocates (with malloc(3)) and returns an array of strings
** obtained by splitting s using the character c as a delimiter
**
** s: The string to be split
** c: The delimiter character
**
** returns: The new strings ended by a NULL pointer
**          NULL otherwise
*/

char			**ft_split(const char *s, char c)
{
	size_t		str_count;
	size_t		i;
	char		**result;
	char		*delim;

	if (!s)
		return (NULL);
	str_count = ft_count_strings(s, c);
	i = 0;
	result = malloc((str_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	delim = ft_strnew(1);
	delim[0] = c;
	result[i] = ft_strtok((char *)s, delim);
	while (result[i] && i++ < str_count)
		result[i] = ft_strtok(NULL, delim);
	ft_strdel(&delim);
	return (result);
}
