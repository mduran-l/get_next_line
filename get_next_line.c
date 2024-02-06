/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:27:07 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/06 13:35:07 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_file(int fd, char *data)
{
	int		reader;
	char	*buff;

	reader = 1;
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	while (reader)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader < 0)
			break ;
		data = ft_strjoin(data, buff);
		if (!data)
			return (NULL);
		if (ft_linelen(buff))
			break ;
	}
	return (free(buff), data);
}

char	*get_next_line(int fd)
{
	static char	*buff = {0};
	char		*line;
	size_t		len;

	if (fd < 0)
		return (NULL);
	if (!buff || (buff && ft_linelen(buff)))
		buff = read_file(fd, buff);
	if (!buff)
		return (NULL);
	len = ft_linelen(buff) + 1;
	line = ft_substr(buff, 0, len);
	if (!line)
		return (NULL);
	buff = ft_substr(buff, len, ft_strlen(buff) - len);
	if (!buff)
		return (free(line), NULL);
	return (line);
}
