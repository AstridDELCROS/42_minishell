/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:11 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 03:36:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_lexer.h"

/*
** Lexer: lexical analyzer
**
** create_lexer()   :  Constructor
** malloc_lexer()   :  Malloc function
** destroy_lexer()  :  Destructor
** free_lexer()     :  Free function
*/

void		create_lexer(t_lexer *lexer, size_t p_capacity)
{
	lexer->pos = DEFAULT_VALUE;
	lexer->size = DEFAULT_SIZE;
	lexer->capacity = p_capacity;
	lexer->input = NULL;
	lexer->tokens = ft_calloc((p_capacity + 1), sizeof(t_token *));
}

t_lexer		*malloc_lexer(size_t p_capacity)
{
	t_lexer	*result;

	result = malloc(sizeof(t_lexer));
	if (!result)
	{
		g_status = EXIT_FAILURE;
		return (NULL);
	}
	create_lexer(result, p_capacity);
	return (result);
}

void		destroy_lexer(t_lexer to_destroy)
{
	if (to_destroy.input)
		ft_strdel(&(to_destroy.input));
	if (to_destroy.tokens)
		delete_tokens(to_destroy.tokens, to_destroy.size);
}

void		free_lexer(t_lexer **to_free)
{
	if (to_free)
	{
		destroy_lexer(**to_free);
		free(*to_free);
		*to_free = NULL;
	}
}
