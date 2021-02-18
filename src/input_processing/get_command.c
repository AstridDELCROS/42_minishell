/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:47:52 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 16:10:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "libft_io.h"
#include "sh_utils.h"
#include "sh_env.h"
#include "sh_subsystems.h"
#include "sh_parser.h"
#include "sh_input_processing.h"

/*
** This function exits if end of input was indicated
*/

static void	handle_eof(t_shctrl *ft_sh)
{
	/* Si l'input est vide, c'est qu'on a reçu EOF (CTRL + D) */
	ft_putchar('\n');
	/* Donc on exit */
	exit_shell(ft_sh);
}

/*
** This function prompts the user for a command
*/

static int	prompt_user(t_shctrl *ft_sh, char *prompt)
{
	int		ret;

	ret = EXIT_SUCCESS;
	if (prompt)
	{
		ft_sh->lexer->input = ft_readline(prompt);
		if (ft_strcmp(prompt, PS2))
			ft_strdel(&prompt);
	}
	else
		ft_sh->lexer->input = ft_readline(PS1);
	/* Si l'input est vide, c'est qu'on a reçu EOF (CTRL + D) */
	if (!ft_sh->lexer->input)
		handle_eof(ft_sh);
	/* On reset l'index du lexer sur l'input à 0 */
	ft_sh->lexer->pos = DEFAULT_VALUE;
	/* On split les tokens */
	ret = tokenize(ft_sh->lexer);
	/* Puis on free l'input */
	ft_strdel(&(ft_sh->lexer->input));
	return (ret);
}

/*
** This function gets the command input and splits it into tokens
*/

int			get_command(t_shctrl *ft_sh)
{
	int		ret;

	ret = EXIT_SUCCESS;
	/* On malloc le lexer */
	ft_sh->lexer = malloc_lexer(DEFAULT_CAPACITY);
	/* Si pas de lexer, on exit */
	if (!ft_sh->lexer)
		exit_shell(ft_sh);
	/* Sinon, tant que l'input n'est pas fini, on affiche le prompt et on attend l'input de l'utilisateur */
	ret = prompt_user(ft_sh, create_prompt());
	while (ret == 1)
		ret = prompt_user(ft_sh, PS2);
	/* Si ret == EXIT_SUCCESS (0), l'input est terminé et on le parse */
	if (ret == EXIT_SUCCESS)
		ret = parse(&(ft_sh->ast), ft_sh->lexer);
	return (ret);
}
