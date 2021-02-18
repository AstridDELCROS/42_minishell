/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:48:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:59:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"
#include "libft_str.h"

/*
** This function applies the function f to each character of the string passed
** as argument to create a new string (with malloc(3)) resulting from successive
** applications of f
**
** s: The string on which to iterate
** f: The function to apply to each character
**
** returns: The string created from the successive applications of f
**          NULL otherwise
*/

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	if (s && f)
	{
		i = 0;
		result = ft_memalloc(ft_strlen(s) + 1);
		if (!result)
			return (NULL);
		while (s[i])
		{
			result[i] = f(i, s[i]);
			i++;
		}
		return (result);
	}
	return (NULL);
}
