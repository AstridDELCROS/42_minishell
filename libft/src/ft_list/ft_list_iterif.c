/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iterif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:40:44 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/01 20:05:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

/*
** This function iterates over the list from node and applies the function f to
** the content of nodes that are "equal" to the reference data
**
** node: Pointer to a node
** f: The address of the function to apply on the list
** data_ref: The data to be compared to the content of each node
*/

void		ft_list_iterif(t_node *node, void (*f)(void *), void *data_ref)
{
	if (!node || !f || !data_ref)
		return ;
	while (node)
	{
		if (node->content == data_ref)
			f(node->content);
		node = node->next;
	}
}
