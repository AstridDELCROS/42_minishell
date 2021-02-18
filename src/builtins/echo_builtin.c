/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 13:34:34 by adelcros          #+#    #+#             */
/*   Updated: 2021/01/02 16:42:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_builtins.h"

/*
** Recoded builtin echo() with option ’-n’
**
** echo [-n] [arg ...]
**     Display the ARGs, separated by a single space character and followed by a
**     newline, on the standard output.
**
** Options:
**  -n    do not append a newline
**
** returns: success
**          non-zero if a write error occurs
*/

/*
** Cas étranges qui sont censés marcher :
**
** echo -nnnnnnnnnnn TEST
** echo -n -n -n TEST
*/

static int	handle_newline_opt(char *arg, int *i, bool *newline)
{
	size_t	j;

	j = 0;
	/* Si l'arg commence par un tiret, on va checke les caractères suivants */
	if (arg[j] == '-')
		j++;
	/* Sinon on return car ce n'est pas une option */
	else
		return (0);
	/* Tant que c'est un 'n' on incrémente */
	while (arg[j] && arg[j] == 'n')
		j++;
	/* S'il reste des lettres mais que c'est pas des 'n' */
	if (arg[j] && arg[j] != 'n')
	/* Ce n'est pas une option mais un arg à imprimer */
		return (0);
	/* Sinon, l'option '-n' s'applique et on n'affiche pas de newline */
	*newline = false;
	/* Et on passer à l'arg suivant pour ne pas print '-n' */
	(*i)++;
	return (1);
}

static int	dislay_args(int argc, char *arg, int *i)
{
	int		ret;

	/* On print un arg */
	ret = ft_printf("%s", arg);
	/* On incrémente i */
	(*i)++;
	if (ret != FAIL_RET)
	{
		/* Si pas d'erreur avec write et que i > argc */
		if (*i < argc)
		/* On print un espace pour séparer du prochain arg */
			ret = ft_printf(" ");
	}
	return (ret);
}

int			echo_builtin(int argc, char **argv)
{
	int		i;
	int		ret;
	int		write_ret;
	bool	newline;

	i = FIRST_PARAM;
	ret = 1;
	write_ret = 0;
	newline = true;
	if (argc > NO_ARGS)
	{
		/* On check d'abord l'option '-n' */
		while (i < argc && ret)
			ret = handle_newline_opt(argv[i], &i, &newline);
		/* On affiche les args */
		while ((i < argc) && (write_ret != FAIL_RET))
			write_ret = dislay_args(argc, argv[i], &i);
	}
	if (newline && (write_ret != FAIL_RET))
		write_ret = ft_printf("\n");
	if (write_ret == FAIL_RET)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
