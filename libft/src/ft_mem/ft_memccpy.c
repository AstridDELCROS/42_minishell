/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:22:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:45:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft_mem.h"

/*
** Recoded memccpy libc function: Copies bytes from memory area src to dst
** stopping after the first occurrence of c or n bytes have been copied
**
** dst: The pointer to the destination array where the content is to be copied
** src: The pointer to the source of data to be copied
** c: The value to stop copying at
** n: The maximum number of bytes to copy
**
** returns: A pointer to the first byte after c in dst
**          NULL otherwise
*/

void		*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	size_t	i;
	uint8_t	*to;
	uint8_t	*from;

	i = 0;
	to = (uint8_t *)dst;
	from = (uint8_t *)src;
	while (n--)
	{
		to[i] = from[i];
		if (from[i] == (uint8_t)c)
			return (to + i + 1);
		i++;
	}
	return (NULL);
}
