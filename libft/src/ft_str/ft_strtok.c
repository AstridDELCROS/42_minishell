/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:34:43 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/18 19:36:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_ctype.h"
#include "libft_str.h"

/*
** This function breaks a string into a sequence of zero or more nonempty tokens
** On the first call, the string to be parsed should be specified in s.
** In each subsequent call that should parse the same string, s must be NULL.
**
** s: The string to be parsed
** delim: The string containing the delimiters
**
** returns: A pointer to the next token
**          NULL if there are no more tokens
*/

char			*ft_strtok(char *s, const char *delim)
{
	static char	*buffer;
	static int	curr_delim = 0;
	int			i;

	if (s)
	{
		buffer = s;
		curr_delim = 0;
	}
	if (!buffer || !delim)
		return (NULL);
	i = curr_delim;
	while (buffer && buffer[curr_delim])
	{
		if (ft_ischarset(buffer[curr_delim], delim))
		{
			if (curr_delim - i > 0)
				return (ft_substr(buffer, i, (curr_delim - i)));
			i = curr_delim + 1;
		}
		curr_delim++;
	}
	if (curr_delim - i > 0)
		return (ft_substr(buffer, i, (curr_delim - i)));
	return (NULL);
}
