/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:24:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:57:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** Recoded strrchr libc function: Locates the last occurrence of c in the
** string pointed to by s
**
** s: The string to be scanned
** c: The character to be searched
**
** returns: A pointer to the located character
**          NULL otherwise
*/

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while ((*(s + i) != (char)c) && (i > 0))
		i--;
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
