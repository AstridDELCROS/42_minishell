/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:36:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/31 03:39:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_stack.h"

/*
** This function inserts an object at the top of the stack
*/

void	ft_push_to_stack(t_stack *stack, char *new_data)
{
	if (ft_stack_is_full(stack))
		ft_increase_stack(stack);
	stack->top += 1;
	stack->content[stack->top] = ft_strdup(new_data);
}
