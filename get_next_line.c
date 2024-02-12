/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:27:07 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/12 14:50:50 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*extract_line(char *buff)
{
	char	*line;
	char	l;

	if (!buff)
		return (NULL);
	l = ft_linelen(buff) + 1;
	line = ft_substr(buff, 0, l);
	if (!line)
	{
		free(buff);
		return (NULL);
	}
	return (line);
}

static char	*clear_buffer(char *buff)
{
	size_t	l;
	size_t	s;
	char	*cleared;

	if (!buff)
		return (NULL);
	l = ft_linelen(buff) + 1;
	s = ft_strlen(buff);
	if (!s)
	{
		free(buff);
		return (NULL);
	}
	cleared = ft_substr(buff, l, s);
	if (!cleared)
		return (NULL);
	free(buff);
	return (cleared);
}

char	*get_next_line(int fd)
{
	static char	*buff = {0};
	char		*line;
	int			rfd;

	rfd = 1;
	if (!fd || !BUFFER_SIZE)
		return (NULL);
	line = (char *)ft_calloc(1 + BUFFER_SIZE, sizeof(char));
	if (!line)
		return (NULL);
	while (rfd && !ft_linelen(line))
	{
		rfd = read(fd, line, BUFFER_SIZE);
		if (rfd < 0)
		{
			free(line);
			return (NULL);
		}
		if (rfd)
			buff = ft_strjoin(buff, line);
	}
	free(line);
	line = extract_line(buff);
	buff = clear_buffer(buff);
	return (line);
}
