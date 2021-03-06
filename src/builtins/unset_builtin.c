/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 13:35:16 by adelcros          #+#    #+#             */
/*   Updated: 2021/01/02 16:36:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "sh_utils.h"
#include "sh_env.h"
#include "sh_builtins.h"

/*
** Recoded builtin unset() without any options
*/

/*
** This function unsets names marked for export
*/

/* Pour unset les variables qui n'ont pas de =
** ex: NAME au lieu de NAME=VALUE
*/

static int	unset_export(char *var)
{
	size_t	count;
	int		to_set;

	count = 0;
	to_set = 0;
	if (!var)
		return (FAIL_RET);
	to_set = ft_findenv(var);
	if (to_set != FAIL_RET)
	{
		g_env[to_set] = ft_strreplace(g_env[to_set], EMPTY_STR);
		if (g_env[to_set])
		{
			count = ft_str_arr_len(g_env);
			g_env = dup_environment(count, true);
			if (!g_env)
				return (FAIL_RET);
		}
	}
	return (0);
}

/*
** unset [name ...]
**     For each NAME, remove the corresponding variable or function.
**
** returns: success
**          non-zero if an invalid option is given or a NAME is read-only
*/

int			unset_builtin(int argc, char **argv)
{
	int		ret;
	int		i;

	ret = EXIT_SUCCESS;
	if (argc == NO_ARGS)
		return (EXIT_SUCCESS);
	i = FIRST_PARAM;
	if (argv[FIRST_PARAM][0] == '-')
	{
		/* On doit faire unset sans option */
		handle_invalid_opt(argv[CMD_NAME], argv[i]);
		print_builtin_usage("unset", "unset [name ...]");
		return (EXIT_FAILURE);
	}
	while (i < argc)
	{
		/* Si l'arg est invalid, on affiche un message d'erreur */
		if ((!is_valid_identifier(argv[i])) || ft_strchr(argv[i], ENV_VAR_SEP))
			ret = handle_invalid_id(argv[CMD_NAME], argv[i]);
		else
		{
			/* Sinon, on unset l'arg qui est le nom d'une variable d'env */
			if (ft_unsetenv(argv[i]) == FAIL_RET)
				unset_export(argv[i]);
		}
		i++;
	}
	return (ret);
}
