/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:33:47 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:59:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"
#include "libft_str.h"

/*
** This function applies the function f to each character of the string given as
** argument to create a “fresh” new string (with malloc(3)) resulting from the
** successive applications of f.
**
** s: The string on which to iterate
** f: The function to apply to each character
**
** returns: The string created from the successive applications of f
**          NULL otherwise
*/

char		*ft_strmap(const char *s, char (*f)(char))
{
	size_t	i;
	char	*result;

	i = 0;
	if (s && f)
	{
		result = ft_memalloc(ft_strlen(s) + 1);
		if (!result)
			return (NULL);
		while (s[i])
		{
			result[i] = f(s[i]);
			i++;
		}
		return (result);
	}
	return (NULL);
}
