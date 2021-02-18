/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:15:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 18:54:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** Recoded strncat libc function that appends no more than n characters of the
** string pointed to by src to the end of the string pointed to by dst and
** null-terminates the resulting string
**
** dst: A pointer to the destination string
** src: A pointer to the source string
** n: The number of characters to append
**
** returns: A pointer to the new string
*/

char		*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	while (src[i] && (i < n))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst);
}
