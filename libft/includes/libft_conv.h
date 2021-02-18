/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_conv.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:30:53 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/05 15:53:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CONV_H
# define LIBFT_CONV_H
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

# define BINARY_BASE 2
# define OCT_BASE 8

int		ft_atoi(const char *s);
int		ft_atoi_dec_base(const char *s, int from_base);
char	*ft_atos(char c);
char	*ft_itoa(int n, char *output, int base);
char	*ft_utoa(int64_t n, char *output, int base);
double	ft_strtod(const char *s, char **endptr);

#endif
