/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:27:07 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/07 14:41:18 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i ++] = 0;
}

char	*read_file(int fd, char *buff)
{
	int		rfd;
	char	*temp;

	rfd = 1;
	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (free(buff), NULL);
	while (rfd && !ft_linelen(buff))
	{
		ft_bzero(temp, BUFFER_SIZE + 1);
		rfd = read(fd, temp, BUFFER_SIZE);
		if (rfd < 0)
			return (free(temp), NULL);
		buff = ft_strjoin(buff, temp);
		if (!buff)
			return (free(temp), NULL);
	}
	return (free(temp), buff);
}

char	*get_next_line(int fd)
{
	static char	*buff = {0};
	char		*line;
	size_t		len;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	if (!buff || (buff && !ft_linelen(buff)))
	{
		buff = read_file(fd, buff);
		if (!buff)
			return (NULL);
	}
	len = ft_linelen(buff) + 1;
	line = ft_substr(buff, 0, len);
	if (!line)
		return (free(buff), NULL);
	buff = ft_substr(buff, len, ft_strlen(buff) - len);
	if (!buff)
		return (free(line), NULL);
	return (line);
}
