/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:43:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:57:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** This function reverses the order of characters in a string.
*/

char		*ft_strrev(char *s)
{
	size_t	i;
	size_t	s_len;
	int		tmp;

	i = 0;
	s_len = ft_strlen(s) - 1;
	while (i < s_len)
	{
		tmp = s[i];
		s[i] = s[s_len];
		s[s_len] = tmp;
		i++;
		s_len--;
	}
	return (s);
}
