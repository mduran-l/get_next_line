/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduran-l <mduran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:41:56 by mduran-l          #+#    #+#             */
/*   Updated: 2024/02/01 14:55:45 by mduran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i ++] = 0;
	}
}

size_t	ft_linelen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] < 0)
			return (i);
		i ++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	if (len > l - (size_t)start)
		len = l - (size_t)start;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	ft_bzero(subs, len + 1);
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
		s1 = malloc(sizeof(char) * 2);
		if (!s1)
			return (NULL);
		ft_bzero(s1, 2);
	}
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	joint = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (!joint)
		return (NULL);
	ft_bzero(joint, l1 + l2 + 1);
	i = -1;
	while (s1[++ i])
		joint[i] = s1[i];
	i = -1;
	while (s2[++ i])
		joint[l1 + i] = s2[i];
	return (joint);
}
