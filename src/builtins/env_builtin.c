/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 13:34:42 by adelcros          #+#    #+#             */
/*   Updated: 2021/01/02 16:37:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_env.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin env() with no options and no arguments
**
** If no command name is specified following the environment specifications,
** the resulting environment is printed. This is like specifying the printenv
** program.
**
** returns: success
**          non-zero if a write error occurs
*/

int		env_builtin(int argc, char **argv)
{
	int	write_ret;

	/* S'il y a des arg, on affiche un message d'erreur */
	if (argc != NO_ARGS)
		return (handle_arg_err(argv[CMD_NAME]));
	/* On appelle ft_printenv() qui est dans src/subsystems/env_utils */
	write_ret = ft_printenv();
	/* S'il y a un pbm avec write, on retourne 1 */
	if (write_ret == FAIL_RET)
		return (EXIT_FAILURE);
	/* Sinon on retourne 0 */
	return (EXIT_SUCCESS);
}
