/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:12:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/31 03:40:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"
#include "libft_str.h"
#include "libft_stack.h"

/*
** Stack (LIFO)
**
** create_stack()   :  Constructor
** malloc_stack()   :  Malloc function
** destroy_stack()  :  Destructor
** free_stack()     :  Free function
*/

void		create_stack(t_stack *stack, size_t p_capacity)
{
	stack->capacity = p_capacity;
	stack->top = DEFAULT_TOP_VAL;
	stack->content = ft_calloc((p_capacity + 1), sizeof(char *));
}

t_stack		*malloc_stack(size_t capacity)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack *));
	if (!result)
		return (NULL);
	create_stack(result, capacity);
	return (result);
}

void		destroy_stack(t_stack to_destroy)
{
	ft_str_arr_del(to_destroy.content);
}

void		free_stack(t_stack **to_free)
{
	if (to_free)
	{
		destroy_stack(**to_free);
		free(*to_free);
		*to_free = NULL;
	}
}
