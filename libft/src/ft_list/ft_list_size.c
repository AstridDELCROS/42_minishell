/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:17:57 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/01 20:06:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

/*
** This function counts the number of nodes in a list
**
** head: Pointer to the first node of a list
**
** returns: The length of the list
*/

int			ft_list_size(t_node *head)
{
	int		size;

	size = 0;
	if (head)
	{
		while (head)
		{
			size++;
			head = head->next;
		}
	}
	return (size);
}
