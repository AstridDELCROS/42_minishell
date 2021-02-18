/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:33:20 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 00:34:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_define.h"
#include "libft_str.h"
#include "libft_printf.h"

/*
** This function checks for a newline character in the content pointed to by
** line. If a newline is found, line is updated and true is returned.
**
** line: The value of what has been read
**
** returns: true if a newline character has been found
**          false otherwise
*/

static bool	ft_is_line(char **line)
{
	char	*newline;
	char	*sub_string;
	size_t	line_end;

	newline = NULL;
	newline = ft_strchr(*line, NEWLINE);
	if (newline != NULL)
	{
		line_end = newline - *line;
		sub_string = ft_substr(*line, 0, line_end);
		*line = ft_strreplace(*line, sub_string);
		ft_strdel(&sub_string);
		return (true);
	}
	return (false);
}

/*
** This function reads a line from the terminal and return it, using prompt as
** a prompt.
** If prompt is NULL or the empty string, no prompt is issued.
** The line returned is allocated with malloc(3); the caller must free it when
** finished.
** The line returned has the final newline removed, so only the text of the
** line remains.
**
** returns: The text of the line read
**          NULL otherwise
*/

char		*ft_readline(const char *prompt)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*line;

	if (BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (prompt)
		ft_printf("%s", prompt);
	while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!(line = ft_strjoindelone(line, buffer)))
			return (NULL);
		if (ft_is_line(&line))
			return (line);
	}
	return (line);
}
