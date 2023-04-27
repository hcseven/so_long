/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcitons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:55:10 by hseven            #+#    #+#             */
/*   Updated: 2022/09/28 21:47:36 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	split_array(char const*s, char c)
{
	size_t	a;
	size_t	b;

	if (c == '\0')
		return (1);
	a = 0;
	b = 0;
	while (s[a] == c)
		a++;
	while (s[a + 1] != '\0')
	{
		if (s[a] == c && s[a + 1] != c)
			b++;
		a++;
	}
	return (b + 1);
}

char	**ft_split(char const *s, char c)
{
	size_t	a;
	size_t	b;
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc((split_array(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	a = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
		b = 0;
			while (*s != c && *s && ++b)
				s++;
			str[++a - 1] = (char *)ft_calloc_gnl(b + 1, sizeof(char));
			ft_strlcpy(str[a - 1], s - b, b + 1);
		}
	}
	return (str);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	a;

	a = 0;
	if (size > a)
	{
		while (src[a] != '\0' && (size - 1) > a)
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	while (src[a] != '\0')
	{
		a++;
	}
	return (a);
}

int	wisp_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_strchr(char	*str, char c)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			a++;
		i++;
	}
	return (a);
}
