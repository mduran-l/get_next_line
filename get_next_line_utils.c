/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:25:57 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/13 10:48:41 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;
	size_t	i;

	out = (void *)malloc(count * size);
	if (!out)
		return (NULL);
	i = 0;
	while (i < count * size)
		((char *)out)[i ++] = 0;
	return (out);
}

size_t	ft_linelen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i ++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i ++;
	return (i);
}

/*
IMPORTANT!: When execution starts, s1 has no data or allocated memory
*/
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joint;

	if (!s1)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	joint = (char *)ft_calloc(1 + ft_strlen(s1) + ft_strlen(s2),
			sizeof(char));
	if (!joint)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++ i])
		joint[i] = s1[i];
	j = -1;
	while (s2[++ j])
		joint[i + j] = s2[j];
	free(s1);
	return (joint);
}
