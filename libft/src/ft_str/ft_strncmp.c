/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:23:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 00:03:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft_str.h"

/*
** Recoded strncmp libc function: Lexicographically compares the null-terminated
** strings s1 and s2
**
** s1, s2: Pointers to the buffers to be compared
** n: The number of bytes to be compared
**
** returns: 0 if the two strings are identical
**          Otherwise the difference between the first two differing bytes
*/

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && (i < (n - 1)))
		i++;
	return ((uint8_t)s1[i] - (uint8_t)s2[i]);
}
