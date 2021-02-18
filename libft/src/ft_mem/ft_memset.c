/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:23:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:46:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft_mem.h"

/*
** Recoded memset libc function: Writes len bytes of value c to string s
**
** s: A pointer to the block of memory to fill
** c: The value to be set
** len: The number of bytes to be set to the value
**
** returns: A pointer to the memory area s
*/

void		*ft_memset(void *s, int c, size_t len)
{
	uint8_t	*p;

	p = (uint8_t *)s;
	while (len--)
		*p++ = c;
	return (s);
}
