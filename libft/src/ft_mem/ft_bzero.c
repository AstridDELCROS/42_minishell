/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:21:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:45:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft_mem.h"

/*
** Recoded bzero libc function: Erases the data in the n bytes of the memory
** starting at the location pointed to by s, by writing zeros
**
** s: An existing object to fill with zeroes
** n: The number of bytes to fill
*/

void		ft_bzero(void *s, size_t n)
{
	uint8_t	*result;

	result = (uint8_t *)s;
	while (n--)
		*result++ = '\0';
}
