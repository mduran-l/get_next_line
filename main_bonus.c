/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:02:58 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/15 13:10:51 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

/*
int	main(void)
{
	char	*tmp = ft_strjoin("Hola ", "caracola");
	printf("%s\n", ft_substr(tmp, 1, 7));
	return (0);
}
//*/
//*
int	main(void)
{
	int		fd[FD_MAX];
	char	*line;

	line = "";
	fd[0] = open("example0.txt", 'r');
	fd[1] = open("example1.txt", 'r');
	fd[2] = open("example2.txt", 'r');
	fd[3] = open("example3.txt", 'r');
	while (line)
	{
		line = get_next_line(fd[0]);
		write(1, line, ft_strlen(line));
		line = get_next_line(fd[1]);
		write(1, line, ft_strlen(line));
		line = get_next_line(fd[2]);
		write(1, line, ft_strlen(line));
		line = get_next_line(fd[3]);
		write(1, line, ft_strlen(line));
	}
	free(line);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	return (0);
}
//*/
