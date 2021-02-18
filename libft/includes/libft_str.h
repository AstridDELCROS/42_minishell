/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:30:53 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 23:05:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
# define LIBFT_STR_H
# include <stdbool.h>
# include <stdlib.h>

char	**ft_split(const char *s, char c);
size_t	ft_str_arr_len(char **arr);
void	ft_str_arr_del(char **to_free);
char	*ft_char_to_str(char *s, char c);
char	*ft_strappend(char *s, char *suffix);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strdel(char **to_free);
char	*ft_strdup(const char *s1);
int		ft_strequ(const char *s1, const char *s2);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoindel(char *s1, char *s2);
char	*ft_strjoindelone(char *s1, const char *s2);
char	*ft_join_n_str(int count, ...);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t n);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strprepend(const char *prefix, char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strreplace(char *s1, char *s2);
char	*ft_strrev(char *s);
char	*ft_strstr(const char *s, const char *needle);
void	ft_strswap(char **a, char **b);
char	*ft_strtok(char *str, const char *delim);
char	*ft_strtrim(const char *s, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strupcase(char *s);
char	*ft_strlowcase(char *s);
char	*ft_append_char(char *s, char *c, bool replace);

#endif
