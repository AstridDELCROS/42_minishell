/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:23:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 20:14:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** Recoded strlcat libc function: Appends the null-terminated string src to the
** end of dst at most size − dst length − 1 bytes, null-terminating the result
**
** dst: A pointer to the destination string
** src: A pointer to the source string
** size: The size of the destination buffer
**
** returns: The total length of the string (dst + src)
*/

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (dst_len + src_len);
	i = dst_len;
	while (*src && (i < (size - 1)))
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (i);
}
