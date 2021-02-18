/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_is_empty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:29:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:57:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_stack.h"

/*
** This function checks whether the stack is empty
*/

bool	ft_stack_is_empty(t_stack *stack)
{
	return (stack->top == DEFAULT_TOP_VAL);
}
