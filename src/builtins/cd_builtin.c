/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:34:33 by adelcros          #+#    #+#             */
/*   Updated: 2021/01/02 16:31:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin cd() with only a relative or absolute path
*/

/*
** This function sets former current directory
*/

static int	set_old_pwd(void)
{
	char	*new_var;
	int		ret;

	new_var = NULL;
	/* Si PWD n'est pas set dans l'environnement, alors on le set */
	if (!ft_getenv("PWD"))
		set_working_dir();
	/* Si OLDPWD est déjà set, on le MÀJ avec la valeur de PWD (puisqu'ensuite on change de dir donc PWD devient OLDPWD) avec ft_setenv() */
	if (ft_findenv("OLDPWD") != FAIL_RET)
		return (ft_setenv("OLDPWD", ft_getenv("PWD"), true));
	/* Si OLPWD n'est pas set, on l'ajoute avec ft_putenv() */
	new_var = ft_join_n_str(2, "OLDPWD=", ft_getenv("PWD"));
	if (new_var)
		ret = ft_putenv(new_var);
	ft_strdel(&new_var);
	return (ret);
}

/*
** This function changes working directory to dir and updates the current
** working directory
*/

static int	set_directory(char *cmd_name, char *dir)
{
	/* On met à jour OLDPWD avec le PWD */
	if (set_old_pwd() == FAIL_RET)
	{
		/* Si erreur, on imprime le message d'erreur et on retourne 1 */
		print_errno(cmd_name);
		return (EXIT_FAILURE);
	}
	/* On change de répertoire */
	if (chdir(dir) == FAIL_RET)
	{
		/* Si erreur, on imprime le message d'erreur et on retourne 1 */
		print_error(3, cmd_name, dir, strerror(errno));
		return (EXIT_FAILURE);
	}
	/* On set le nouveau PWD */
	set_working_dir();
	return (0);
}

/*
** This function retrieves the dir name to change the working directory
*/

/* Cet fonction gère :
** cd (on retourne à $HOME)
** cd - (on retourne à $OLDPWD)
*/

static int	change_to_directory(char *cmd_name, char *dir_name)
{
	char	*path;
	int		ret;

	path = NULL;
	ret = EXIT_FAILURE;
	if (!ft_getenv(dir_name))
	{
		/* Si HOME ou OLDPWD n'existent pas, erreur */
		handle_env_not_set(cmd_name, dir_name);
		return (ret);
	}
	path = ft_strdup(ft_getenv(dir_name));
	if (!path)
		return (ret);
	/* Sinon, on change de dir */
	ret = set_directory(cmd_name, path);
	ft_strdel(&path);
	return (ret);
}

/*
** cd [dir]
**     Change the current directory to DIR. The default DIR is the value of the
**     HOME shell variable.
**
** `cd' without arguments is equivalent to `cd $HOME'
** `cd -' is equivalent to `cd $OLDPWD' and the new directory name is echoed to
**   stdout
**
** returns: 0 if the directory is changed
**          non-zero otherwise
*/

int			cd_builtin(int argc, char **argv)
{
	int		ret;

	ret = 0;
	if (argc > 2)
		return (handle_arg_err(argv[CMD_NAME]));
	/* Si pas d'arguments, cd retourne à $HOME */
	if (argc == NO_ARGS)
		ret = change_to_directory(argv[CMD_NAME], "HOME");
	/* Si cd -, retourne à $OLDPWD */
	else if (!ft_strcmp(argv[FIRST_PARAM], "-"))
	{
		ret = change_to_directory(argv[CMD_NAME], "OLDPWD");
		if (!ret)
			ft_printf("%s\n", ft_getenv("PWD"));
	}
	/* Sinon, on va à cd argv[1] */
	else
		ret = set_directory(argv[CMD_NAME], argv[FIRST_PARAM]);
	return (ret);
}
