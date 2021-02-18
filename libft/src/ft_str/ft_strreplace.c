/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 19:47:13 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/08 19:48:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** This function duplicates s2 and frees s1
**
** s1: A pointer to the string to free
** s2: A pointer to the new content
**
** returns: The new string
**          NULL otherwise
*/

char		*ft_strreplace(char *s1, char *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = ft_strdup(s2);
	ft_strdel(&s1);
	return (result);
}
