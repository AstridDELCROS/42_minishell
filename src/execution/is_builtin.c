/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:35:35 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 16:06:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "sh_execution.h"

/*
** This function checks whether the current simple command is a builtin
*/

/* Si la commande est une builtin, le pointeur builtin_func ne sera pas NULL */

bool	is_builtin(t_simplecmd *simple_cmd)
{
	return (simple_cmd->builtin_func);
}
