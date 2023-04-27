/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:44:50 by hseven            #+#    #+#             */
/*   Updated: 2022/09/30 13:41:30 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_find_n(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{	
		s[i] = str[i];
		i += 1;
	}
	s[i] = '\0';
	return (s);
}

char	*get_last(char	*str)
{
	int		j;
	int		i;
	char	*s;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	s = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
	i += 1;
	j = 0;
	while (str[i] != '\0')
		s[j++] = str[i++];
	s[j] = '\0';
	free (str);
	return (s);
}

char	*get_read(char *str, int fd)
{
	int		a;
	char	*s;

	s = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	a = 4;
	while (check(s) && a != 0)
	{
		a = read(fd, s, BUFFER_SIZE);
		if (a == -1)
		{
			free (s);
			return (0);
		}
		s[a] = '\0';
		str = ft_strjoin(str, s);
	}
	free (s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ptr;

	if (BUFFER_SIZE <= 0 && fd < 0)
		return (0);
	str = get_read(str, fd);
	if (!str)
		return (0);
	ptr = get_find_n(str);
	str = get_last(str);
	return (ptr);
}
