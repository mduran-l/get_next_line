/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:25:57 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/13 15:14:42 by mduran-l         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s || !s[0])
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i ++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i ++;
	return (i);
}

size_t	ft_linelen(const char *s)
{
	size_t	i;

	if (!s || !s[0])
		return (0);
	i = 1;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i ++;
	}
	return (0);
}

/*
IMPORTANT!: When execution starts, s1 has no data or allocated memory
*/
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*joint;

	if (!s1)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		if (!s1)
			return (freeall(&s2, NULL));
	}
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	joint = (char *)ft_calloc(1 + i + j, sizeof(char));
	if (!joint)
		return (freeall(&s1, &s2));
	i = -1;
	while (s1[++ i])
		joint[i] = s1[i];
	j = -1;
	while (s2[++ j])
		joint[i + j] = s2[j];
	free(s1);
	return (joint);
}
