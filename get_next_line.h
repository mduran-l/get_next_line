/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:41:35 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/13 10:21:00 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char *s, size_t start, size_t len);
size_t	ft_linelen(char *s);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *dst, char *src);
char	*get_next_line(int fd);
#endif
