/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 13:34:49 by adelcros          #+#    #+#             */
/*   Updated: 2021/01/02 16:44:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_num.h"
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin exit() without any options
*/

/*
** This function checks if the parameter is numeric (the exit value) and if
** there is no more than one parameter
*/

static int	check_args(int argc, char *cmd_name, char *n)
{
	if (!ft_isnumeric(n))
	{
		g_status = INCORRECT_USAGE;
		print_error(3, cmd_name, n, "numeric argument required");
		return (1);
	}
	if (argc > 2)
		return (handle_arg_err(cmd_name));
	return (0);
}

/*
** Exit value is an integer in the range (0, 255)
** 255 = MAX_EXIT_VALUE
** 256 = MAX_STATES
**
** A value greater than 255 returns:
**   exit code % 256
** A negative value (lesser than 0) returns:
**   exit code % 256 + 256 (so it becomes positive)
*/

static void	get_exit_status(char *str_repr)
{
	int		n;

	n = ft_atoi(str_repr);
	if (n > MAX_EXIT_VALUE)
		g_status = n % MAX_STATES;
	else if (n < 0)
		g_status = n % MAX_STATES + MAX_STATES;
	else
		g_status = n;
}

/*
** exit [n]
**     Exits the shell with a status of n (an integer in the range (0, 255)).
**     If n is omitted, the exit status is that of the last command executed.
*/

/* Programme terminé */
/* Fonction qui s'appelle jump_to_top_level car dans bash, elle existe pour signale que le programme est fini */

static void	jump_to_top_level(void)
{
	g_done = true;
}

int			exit_builtin(int argc, char **argv)
{
	ft_printf("exit\n");
	if (argc > NO_ARGS)
	{
		/* Si y a des args, on checke les erreurs */
		if (!check_args(argc, argv[CMD_NAME], argv[FIRST_PARAM]))
		/* Si pas d'erreur, on récupère le status et on MÀJ g_status */
			get_exit_status(argv[FIRST_PARAM]);
	}
	/* C'est pour signaler que le programme est terminé */
	jump_to_top_level();
	/* On retourne le status */
	return (g_status);
}
