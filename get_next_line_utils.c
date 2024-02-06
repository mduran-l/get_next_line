/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:41:56 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/06 13:19:16 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*out;

	if (!count || !size)
		return (NULL);
	out = (void *)malloc(count * size);
	if (!out)
		return (NULL);
	i = 0;
	while (i < count * size)
		((char *)out)[i ++] = 0;
	return (out);
}

size_t	ft_linelen(const char *s)
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

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*subs;

	l = ft_strlen(s);
	if (start >= l)
	{
		start = l;
		len = 0;
	}
	if (len > l - start)
		len = l - start;
	subs = ft_calloc(len + 1, sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (len --)
		subs[i ++] = s[start ++];
	return (subs);
}

/*
IMPORTANT!: When execution starts, s1 has no data or allocated memory
*/
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	int		i;
	char	*joint;

	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	joint = ft_calloc(l1 + l2 + 1, sizeof(char));
	if (!joint)
		return (free(s1), NULL);
	i = -1;
	while (s1[++ i])
		joint[i] = s1[i];
	i = -1;
	while (s2[++ i])
		joint[l1 + i] = s2[i];
	return (joint);
}
