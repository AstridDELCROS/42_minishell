/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:49:05 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 03:37:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "sh_command.h"

/*
** Command
**
** malloc_cmd()   :  Malloc function
** destroy_cmd()  :  Destructor
** free_cmd()     :  Free function
*/

t_cmd		*malloc_cmd(size_t p_capacity)
{
	t_cmd	*result;

	result = malloc(sizeof(t_cmd));
	if (!result)
	{
		g_status = EXIT_FAILURE;
		return (NULL);
	}
	result->capacity = p_capacity;
	result->curr_cmd = DEFAULT_VALUE;
	result->cmd_count = DEFAULT_VALUE;
	result->simple_cmds = malloc(p_capacity * sizeof(t_simplecmd *));
	return (result);
}

void		destroy_cmd(t_cmd to_destroy)
{
	size_t	i;

	i = 0;
	if (to_destroy.cmd_count)
	{
		while (i < to_destroy.cmd_count)
			free_simple_cmd(to_destroy.simple_cmds[i++]);
	}
	free(to_destroy.simple_cmds);
	to_destroy.simple_cmds = NULL;
}

void		free_cmd(t_cmd **to_free)
{
	if (to_free)
	{
		destroy_cmd(**to_free);
		free(*to_free);
		*to_free = NULL;
	}
}
