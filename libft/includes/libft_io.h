/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:30:53 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/12 13:40:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H
# include <unistd.h>
# include <stdlib.h>
# include "libft_define.h"

/*
** With the GNU C Library, EOF is -1
** In other libraries, its value may be some other negative number
*/

# define FT_EOF -1

/*
** IO file
**
** head: Current read pointer
** count: The number of chars in the buffer
** buffer: The data storage area
** fd: File descriptor
*/

typedef struct	s_file
{
	char		*head;
	int			fd;
	size_t		count;
	char		buffer[BUFFER_SIZE + 1];
}				t_file;

int				ft_fileno(t_file *stream);
int				ft_fgetc(t_file *stream);
int				ft_getchar(void);
int				get_next_line(int fd, char **line);
char			*ft_readline(const char *prompt);

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char *s);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char *s);
void			ft_putstr_fd(char *s, int fd);

#endif
