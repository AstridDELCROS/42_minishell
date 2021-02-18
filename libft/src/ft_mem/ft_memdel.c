/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 21:33:43 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:46:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

/*
** This function takes as a parameter the address of a memory area that needs
** to be freed with free(3), then puts the pointer to NULL.
*/

void	ft_memdel(void **to_free)
{
	if (to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
}
