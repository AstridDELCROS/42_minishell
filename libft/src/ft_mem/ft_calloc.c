/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:21:34 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 15:56:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

/*
** Recoded calloc libc function: Allocates enough space for count objects that
** are size bytes of memory each
**
** count: The number of elements to be allocated
** size: The size of elements
**
** returns: A pointer to the allocated memory filled with bytes of value zero
**          NULL otherwise
*/

void		*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if ((count == 0) || (size == 0))
		return (NULL);
	result = malloc(count * size);
	if (!result)
		return (NULL);
	return (ft_memset(result, 0, count * size));
}
