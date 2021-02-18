/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:40:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 00:34:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include "libft_str.h"
#include "libft_io.h"

/*
** This function checks for a newline character in the content pointed to by
** store and updates the content of store and line
**
** store: Saved read content
** line: The value of what has been read
**
** returns: true if a newline character has been found
**          false otherwise
*/

static bool		ft_is_line(char **store, char **line)
{
	char		*newline;
	size_t		line_end;
	size_t		store_start;

	store_start = 0;
	newline = NULL;
	newline = ft_strchr(*store, NEWLINE);
	if (newline != NULL)
	{
		line_end = newline - *store;
		store_start = ft_strlen(newline);
		*line = ft_substr(*store, 0, line_end);
		ft_strlcpy(*store, (newline + 1), (store_start + 1));
		return (true);
	}
	return (false);
}

/*
** This function gets a line read from a file descriptor, without the newline
**
** fd: File descriptor for reading
** line: The value of what has been read
**
** returns: 1 if a line has been read
**          0 if EOF has been reached
**          -1 if an error happened
*/

int				get_next_line(int fd, char **line)
{
	int			bytes_read;
	char		buffer[BUFFER_SIZE + 1];
	static char	*store;

	if ((!line) || (fd < 0) || (BUFFER_SIZE < 1))
		return (-1);
	if (store && ft_is_line(&store, line))
		return (1);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!(store = ft_strjoindelone(store, buffer)))
			return (-1);
		if (ft_is_line(&store, line))
			return (1);
	}
	if (store && *store)
	{
		*line = ft_strdup(store);
		bytes_read = 1;
	}
	else
		*line = NULL;
	ft_strdel(&store);
	return (bytes_read);
}
