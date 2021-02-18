/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 20:58:04 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 23:57:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** This function converts all upper-case letters of s to lower-case letters
*/

char		*ft_strlowcase(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
			s[i] += 32;
		i++;
	}
	return (s);
}
