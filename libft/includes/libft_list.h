/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:30:53 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/18 17:32:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H
# include <stdlib.h>

typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

void				ft_list_append(t_node **head, t_node *new_node);
t_node				*ft_list_at(t_node *head, unsigned int n);
void				ft_list_del(t_node **node);
void				ft_list_delif(t_node **head, void *data_ref);
t_node				*ft_list_find(t_node *head, void *data_ref);
void				ft_list_iter(t_node *node, void (*f)(void *));
void				ft_list_iterif(
	t_node *lst, void (*f)(void *), void *data_ref);
t_node				*ft_list_last(t_node *node);
t_node				*ft_list_new(void *p_content);
void				ft_list_prepend(t_node **head, t_node *new_node);
int					ft_list_size(t_node *head);

#endif
