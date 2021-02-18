/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:46:51 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/05 18:46:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

/*
** This function deletes and frees the given node and its successors using the
** function free(3)
** Finally, the pointer to the list must be set to NULL
**
** node: Pointer to a node
*/

void		ft_list_del(t_node **node)
{
	t_node	*cursor;
	t_node	*next_node;

	if (!node)
		return ;
	if (*node)
	{
		cursor = *node;
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor);
			cursor = next_node;
		}
		*node = NULL;
	}
}
