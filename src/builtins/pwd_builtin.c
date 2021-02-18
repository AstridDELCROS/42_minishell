/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 13:35:09 by adelcros          #+#    #+#             */
/*   Updated: 2021/01/02 16:36:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin pwd() without any options
**
** pwd
**     Print the name of the current working directory.
**
** returns: 0
**          non-zero if an invalid option is given or the current directory
**          cannot be read
*/

int			pwd_builtin(int argc, char **argv)
{
	char	cwd[PATH_MAX];

	if (argc != NO_ARGS)
	{
		if (argv[FIRST_PARAM][0] == '-')
		{
			/* Si l'argument est invalide, on affiche un message d'erreur */
			/* On ne doit pas gérer d'option */
			handle_invalid_opt(argv[CMD_NAME], argv[FIRST_PARAM]);
			print_builtin_usage("pwd", "pwd");
			return (EXIT_FAILURE);
		}
	}
	if (!getcwd(cwd, PATH_MAX))
	{
		print_errno(argv[CMD_NAME]);
		return (EXIT_FAILURE);
	}
	ft_printf("%s\n", cwd);
	return (0);
}
