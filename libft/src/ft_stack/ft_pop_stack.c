/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:36:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/31 03:39:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_stack.h"

/*
** This function pops out the object at the top of the stack
*/

char		*ft_pop_stack(t_stack *stack)
{
	char	*top_obj;

	top_obj = ft_peek_stack(stack);
	if (top_obj)
		stack->top -= 1;
	return (top_obj);
}
