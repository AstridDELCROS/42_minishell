/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:25:33 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 20:44:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** This function allocates (with malloc(3)) and returns a new string, result of
** the concatenation of s1 and s2
**
** s1: The prefix string
** s2: The suffix string
**
** returns: The new string
**          NULL otherwise
*/

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len = len_s1 + ft_strlen(s2);
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, (len_s1 + 1));
	ft_strlcat(result, s2, (len + 1));
	return (result);
}
