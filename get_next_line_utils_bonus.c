/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:25:57 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/15 12:18:54 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;

	out = (void *)malloc(count * size);
	if (!out)
		return (NULL);
	ft_bzero(out, count * size);
	return (out);
}

void	ft_bzero(void *var, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		((char *)var)[i ++] = 0;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i ++;
	return (i);
}

int	ft_linelen(const char *s)
{
	int	i;

	if (!s || !s[0])
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i ++;
	}
	return (-1);
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
			return (NULL);
	}
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	joint = (char *)ft_calloc(1 + i + j, sizeof(char));
	if (!joint)
		return (freeall(&s1, NULL));
	i = -1;
	while (s1[++ i])
		joint[i] = s1[i];
	j = -1;
	while (s2[++ j])
		joint[i + j] = s2[j];
	freeall(&s1, NULL);
	return (joint);
}
