/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ast.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:34:29 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 15:47:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_AST_H
# define SH_AST_H

# include "sh_define.h"

/*
** Node types
**
** Types de noeud de l'AST (Abstract Syntax Tree) utilisé pour le parsing
**
** PROGRAM: noeud "racine" (le premier)
** CMD: une commande complète (plusieurs simple_cmd séparées par des ';')
** SIMPLE_CMD: une commande simple (par ex: 'ls' ou 'ls -l')
** PIPE_SEQ: Plusieurs simple_cmd séparées par des '|'
** CMD_SUFFIX: ce qu'il y a après une simple_cmd (redirections et arguments)
*/

typedef enum			e_node_type
{
	NODE_PROGRAM = 0,
	NODE_CMD,
	NODE_CMD_SUFFIX,
	NODE_IO_FILE,
	NODE_PIPE_SEQ,
	NODE_SIMPLE_CMD,
	NODE_WORD
}						t_node_type;

/*
** Abstract Syntax Tree (AST) node
**
** type: The node type
** left: Pointer to the left node
** right: Pointer to the right node
** data: The node data
*/

typedef struct			s_ast_node
{
	t_node_type			type;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
	char				*data;
}						t_ast_node;

/*
** Abstract Syntax Tree (AST)
**
** create_tree_root()  :  Malloc and construct root node
** create_ast_node()   :  Constructor
** malloc_ast_node()   :  Malloc function
** free_ast()          :  Free function
*/

void					create_tree_root(t_ast_node **root);
t_ast_node				create_ast_node(t_node_type p_type, char *p_data);
t_ast_node				*malloc_ast_node(t_node_type p_type, char *p_data);
void					free_ast(t_ast_node **to_free);

/*
** Adds a leaf node to the left of the tree
*/

void					append_node_left(
	t_ast_node **node, t_ast_node *new_node);

/*
** Adds a leaf node to the right of the tree
*/

void					append_node_right(
	t_ast_node **node, t_ast_node *new_node);

#endif
