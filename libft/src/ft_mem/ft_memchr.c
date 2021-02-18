/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:22:47 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:45:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft_mem.h"

/*
** Recoded memchr libc function: Locates the first occurrence of c
**
** s: The pointer to the block of memory where the search is performed
** c: The value to find
** n: The number of bytes to be analyzed
**
** returns: A pointer to the byte located
**          NULL otherwise
*/

void		*ft_memchr(void const *s, int c, size_t n)
{
	size_t	i;
	uint8_t	*from;
	uint8_t	to_find;

	i = 0;
	from = (uint8_t *)s;
	to_find = (uint8_t)c;
	while (n--)
	{
		if (from[i] == to_find)
			return (from + i);
		i++;
	}
	return (NULL);
}
