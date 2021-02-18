/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:05:45 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/01 20:12:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"

/*
** This function outputs the character c to given file descriptor
**
** c: The character to output
** fd: The file descriptor on which to write
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
