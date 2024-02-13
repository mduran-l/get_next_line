/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:27:07 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/13 12:12:17 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*extract_line(char *buff)
{
	char	*line;
	size_t	i;

	if (!ft_strlen(buff))
		return (NULL);
	i = ft_linelen(buff);
	if (!i)
		i = ft_strlen(buff);
	if (!i)
		return (NULL);
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i ++;
	}
	if (buff[i])
		line[i] = buff[i];
	return (line);
}

static char	*clear_buffer(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	size_t	s;
	char	*cleared;

	s = ft_strlen(buff);
	i = ft_strlen(line);
	if (!(s - i))
	{
		free(buff);
		return (NULL);
	}
	cleared = ft_calloc(s - i, sizeof(char));
	if (!cleared)
		return (NULL);
	j = 0;
	while (buff[i])
		cleared[j++] = buff[i++];
	cleared[j] = 0;
	free(buff);
	return (cleared);
}

char	*get_next_line(int fd)
{
	static char	*buff = {0};
	char		*line;
	int			fd_read;

	fd_read = 1;
	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	line = (char *)ft_calloc(1 + BUFFER_SIZE, sizeof(char));
	if (!line)
		return (NULL);
	while (fd_read && !ft_linelen(line))
	{
		fd_read = read(fd, line, BUFFER_SIZE);
		if (fd_read < 0)
		{
			free(line);
			return (NULL);
		}
		if (fd_read)
			buff = ft_strjoin(buff, line);
	}
	free(line);
	line = extract_line(buff);
	buff = clear_buffer(line, buff);
	return (line);
}
