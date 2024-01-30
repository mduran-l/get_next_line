/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:41:42 by mduran-l          #+#    #+#             */
/*   Updated: 2024/01/30 13:36:07 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_from_file(int fd)
{
	int		reader;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	reader = read(fd, buff, BUFFER_SIZE);
	if (reader <= 0)
		return (free(buff), NULL);
	return (buff);
}

char	*get_next_line(int fd)
{
	size_t		nb;
	static char	*buff = {0};

	nb = linelen(buff);
	while (!nb) {
		buff = read_from_file(fd);
		nb = lilelen(buff);
	}
	return (0);
}
