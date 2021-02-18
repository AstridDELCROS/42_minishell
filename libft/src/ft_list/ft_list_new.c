/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:33:28 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/01 20:05:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

/*
** This function allocates (with malloc(3)) and returns a new node
** The variable content is initialized with the value of the parameter content
** The variable next is initialized to NULL.
**
** p_content: The content of the new node
**
** returns: The new node
*/

t_node		*ft_list_new(void *p_content)
{
	t_node	*result;

	result = malloc(sizeof(t_node));
	if (!result)
		return (NULL);
	result->content = p_content;
	result->next = NULL;
	return (result);
}
