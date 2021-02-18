/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increase_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:36:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/31 03:35:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"
#include "libft_str.h"
#include "libft_stack.h"

/*
** This function doubles the capacity of the stack
*/

void	ft_increase_stack(t_stack *stack)
{
	stack->capacity *= 2;
	stack->content = ft_reallocarray(
		stack->content, stack->capacity, sizeof(char *));
}
