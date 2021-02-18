/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:23:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:46:12 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft_mem.h"

/*
** Recoded memmove libc function: Copies len characters from src to dst
**
** dst: The pointer to the destination array where the content is to be copied
** src: The pointer to the source of data to be copied
** len: The number of bytes to copy
**
** returns: The original value of dst
*/

void		*ft_memmove(void *dst, void const *src, size_t len)
{
	uint8_t	*from;
	uint8_t	*to;

	if ((len == 0) || (dst == src))
		return (dst);
	from = (uint8_t *)dst;
	to = (uint8_t *)src;
	if (dst < src)
		return (ft_memcpy(from, to, len));
	else
	{
		from = from + len - 1;
		to = to + len - 1;
		while (len--)
			*from-- = *to--;
	}
	return (dst);
}
