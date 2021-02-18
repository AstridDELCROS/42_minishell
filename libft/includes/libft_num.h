/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_num.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:30:53 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/05 15:54:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NUM_H
# define LIBFT_NUM_H
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

void	ft_swap(int *a, int *b);
size_t	ft_nbrlen(int n);
size_t	ft_nbrlen_base(int n, int base);
size_t	ft_unbrlen_base(int64_t n, int base);
bool	ft_n_range(int x, int start, int end);
bool	ft_f_range(double x, double start, double end);

#endif
