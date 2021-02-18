/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:51:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/01 20:12:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft_io.h"

/*
** This function reads the next character from stream and returns it as an
** unsigned char cast to an int
**
** stream: An open file
**         Refer to libft_io.h
**
** returns: The character read cast to an int
**          EOF on end of file or error
*/

int			ft_fgetc(t_file *stream)
{
	uint8_t	c;
	size_t	bytes_read;

	if (ft_fileno(stream) != -1)
	{
		bytes_read = read(stream->fd, stream->buffer, 1);
		stream->buffer[bytes_read] = '\0';
		if (bytes_read == 1)
		{
			c = *(stream->buffer);
			stream->head = stream->buffer;
			stream->count += bytes_read;
			return ((int)c);
		}
	}
	return (FT_EOF);
}
