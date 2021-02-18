/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_delif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:08:20 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/05 17:55:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

/*
** This function erases off the list all nodes, whose data is "equal" to the
** reference data
**
** head: Pointer to the first node of a list
** data_ref: The data to be compared to the content
*/

void		ft_list_delif(t_node **head, void *data_ref)
{
	t_node	*cursor;
	t_node	*to_free;

	if (!head || !data_ref)
		return ;
	cursor = NULL;
	to_free = NULL;
	while (*head && (*head)->content == data_ref)
	{
		to_free = *head;
		*head = (*head)->next;
		free(to_free);
	}
	cursor = *head;
	while (cursor)
	{
		if (cursor->next && cursor->next->content == data_ref)
		{
			to_free = cursor->next;
			cursor->next = to_free->next;
			free(to_free);
		}
		cursor = cursor->next;
	}
}
