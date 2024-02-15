/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:27:07 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/15 10:13:00 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*freeall(char **s1, char **s2)
{
	if (s1 != NULL && *s1 != NULL)
		free(*s1);
	if (s2 != NULL && *s2 != NULL)
		free(*s2);
	return (NULL);
}

static char	*extract_line(char *buff)
{
	char	*line;
	int		i;

	if (!buff)
		return (NULL);
	i = ft_linelen(buff) + 1;
	if (!i)
		i = ft_strlen(buff);
	if (!i)
		return (NULL);
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (buff[++i] && buff[i] != '\n')
		line[i] = buff[i];
	if (buff[i] == '\n')
		line[i] = '\n';
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
		return (freeall(&buff, NULL));
	cleared = ft_calloc(s - i + 1, sizeof(char));
	if (!cleared)
		return (freeall(&buff, NULL));
	j = 0;
	while (buff[i])
		cleared[j++] = buff[i++];
	free(buff);
	return (cleared);
}

char	*get_next_line(int fd)
{
	static char	*buff = {0};
	char		*line;
	int			fd_read;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	line = (char *)ft_calloc(1 + BUFFER_SIZE, sizeof(char));
	if (!line)
		return (NULL);
	fd_read = 1;
	while (fd_read && ft_linelen(line) < 0)
	{
		ft_bzero(line, (BUFFER_SIZE + 1) * sizeof(char));
		fd_read = read(fd, line, BUFFER_SIZE);
		if (fd_read < 0)
			return (freeall(&line, &buff));
		buff = ft_strjoin(buff, line);
		if (!buff)
			return (freeall(&buff, &line));
	}
	free(line);
	line = extract_line(buff);
	buff = clear_buffer(line, buff);
	return (line);
}
