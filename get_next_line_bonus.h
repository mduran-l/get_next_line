/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:41:35 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/15 12:19:40 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef FD_MAX
#  define FD_MAX 1024
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*freeall(char **s1, char **s2);
void	ft_bzero(void *var, size_t size);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char *s, size_t start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_linelen(const char *s);
char	*ft_strjoin(char *dst, char *src);
char	*get_next_line(int fd);
#endif
