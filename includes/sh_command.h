/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_command.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:09:32 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 03:26:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_COMMAND_H
# define SH_COMMAND_H

# include "sh_define.h"

typedef	int		(*t_builtin)(int argc, char **argv);

typedef struct	s_builtin_list
{
	char		*name;
	t_builtin	func;
}				t_builtin_list;

/*
** Simple command
**
** argc: The number of arguments
** builtin_func: Pointer to a shell builtin (Default: NULL)
** cmd_path: The path to the file being executed
** cmd_args: The filename (cmd_args[0]) followed by command-line arguments
** input_fd: Input file (Default: -1)
** output_fd: Output file (Default: -1)
*/

typedef struct	s_simplecmd
{
	size_t		argc;
	t_builtin	builtin_func;
	char		*cmd_path;
	char		**cmd_args;
	int			input_fd;
	int			output_fd;
}				t_simplecmd;

/*
** Command
**
** capacity: Maximum capacity of the command
** curr_cmd: Index of the current command
** cmd_count: The number of simple commands
** simple_cmds: The simple commands contained in the command
*/

typedef struct	s_cmd
{
	size_t		capacity;
	size_t		curr_cmd;
	size_t		cmd_count;
	t_simplecmd	**simple_cmds;
}				t_cmd;

/*
** Simple command
**
** malloc_simple_cmd()  :  Malloc function
** free_simple_cmd()    :  Free function
*/

t_simplecmd		*malloc_simple_cmd(void);
void			free_simple_cmd(t_simplecmd *to_free);

/*
** Command
**
** malloc_cmd()   :  Malloc function
** destroy_cmd()  :  Destructor
** free_cmd()     :  Free function
*/

t_cmd			*malloc_cmd(size_t p_capacity);
void			destroy_cmd(t_cmd to_destroy);
void			free_cmd(t_cmd **to_free);

#endif
