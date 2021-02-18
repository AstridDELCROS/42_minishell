/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:40:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/12 13:40:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctype.h"
#include "libft_io.h"

/*
** This function reads the next character from stdin and returns it as an
** unsigned char cast to an int
**
** returns: The character read cast to an int
**          EOF on end of file or error
*/

int			ft_getchar(void)
{
	char	buffer[2];
	size_t	bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, 1);
	if (bytes_read == 1)
	{
		buffer[bytes_read] = '\0';
		return ((int)buffer[0]);
	}
	return (FT_EOF);
}
