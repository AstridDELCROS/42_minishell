/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 13:34:25 by adelcros          #+#    #+#             */
/*   Updated: 2021/01/02 16:51:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_env.h"
#include "sh_builtins.h"

/*
** This functions displays all exported variables
**
** If no names are given, or if the -p option is supplied, a list of names of
** all exported variables is printed.
**
** Format: declare -x VAR
** declare -x: Mark names for export via the environment
*/

static char	**sort_export_list(void)
{
	char	**result;
	size_t	i;
	size_t	j;

	i = 0;
	/* On duplique l'environnement pour avoir une copie triée qu'on supprimera à la fin d'export() */
	result = dup_environment(ft_str_arr_len(g_env), false);
	if (!result)
		return (NULL);
	while (result[i])
	{
		j = 0;
		while (result[j])
		{
			/* Bubble sort avec strcmp */
			if (ft_strcmp(result[i], result[j]) < 0)
				ft_strswap(&(result[j]), &(result[i]));
			j++;
		}
		i++;
	}
	return (result);
}

/*
** On print les paires NAME VALUE ainsi :
** declare -x NAME="VALUE"
**
** Pour les variables sans VALUE :
** declare -x NAME=""
*/

static int	print_key_value(char *sorted_env)
{
	int		ret;
	size_t	i;
	size_t	len;
	char	*value;

	value = NULL;
	if (!sorted_env)
		return (FAIL_RET);
	ret = EXIT_SUCCESS;
	i = get_env_len(sorted_env);
	len = ft_strlen(sorted_env) - i;
	value = ft_substr(sorted_env, (i + 1), len);
	ret = ft_printf("declare -x %.*s=\"%s\"\n", i, sorted_env, value);
	ft_strdel(&value);
	return (ret);
}

static int	print_env_var(char **sorted_env)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = EXIT_SUCCESS;
	if (sorted_env && sorted_env[i])
	{
		while (sorted_env[i] && (ret != FAIL_RET))
		{
			/* On prefix chaque variable par 'declare -x' */
			/* 'declare -x' ça veut juste dire que la var est marquée pour l'export */
			/* Si la var n'a pas de '=' (ENV_VAR_SEP c'est '=') on la print */
			if (!ft_strchr(sorted_env[i], ENV_VAR_SEP))
				ret = ft_printf("declare -x %s\n", sorted_env[i]);
			/* Sinon, si ce n'est pas la var _ qui contient le dernier programme lancé, on la print */
			/* _ n'est pas print par export */
			else if (ft_strncmp(sorted_env[i], "_=", 2))
				ret = print_key_value(sorted_env[i]);
			i++;
		}
		return (ret);
	}
	return (FAIL_RET);
}

int			display_export(void)
{
	char	**sorted_env;
	int		ret;

	sorted_env = NULL;
	/* On sort par ordre ASCII */
	sorted_env = sort_export_list();
	if (sorted_env)
	{
		/* Si y a pas eu d'erreur de malloc, on affiche l'env */
		ret = print_env_var(sorted_env);
		ft_str_arr_del(sorted_env);
		if (ret == FAIL_RET)
		{
			/* Si y a eu une errer avec write, on affiche le message d'erreur */
			print_errno("write error");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
