/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:18:29 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 19:11:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

/*
** This function handles each encountered token, ignores EAT tokens (tabs,
** spaces) and adds them to the lexer, then increments the index on the string
** input
*/

void	handle_token(t_lexer *lexer, t_regex token, char **stack)
{
	if (*stack && stack)
		add_word_to_lexer(lexer, stack);
	if (token.type != TOKEN_EAT)
		add_token_to_lexer(lexer, token.op, token.len, token.type);
	lexer->pos += token.len;
}
