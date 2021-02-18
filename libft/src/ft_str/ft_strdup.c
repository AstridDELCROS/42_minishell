/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:23:32 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:57:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** Recoded strdup libc function: Allocates sufficient memory for a copy of the
** string s1, does the copy, and returns a pointer to it
**
** s1: The string to be copied
**
** returns: A pointer to the copy
**          NULL otherwise
*/

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*result;

	len = ft_strlen(s1);
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, (len + 1));
	return (result);
}
