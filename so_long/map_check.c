/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:26:33 by hseven            #+#    #+#             */
/*   Updated: 2022/09/30 13:36:42 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_data *map)
{
	char	*s;

	s = get_next_line(fd);
	map->width = map_length(s);
	map->map = malloc(sizeof(char) * 1);
	map->map[0] = '\0';
	map->vp_map = malloc(sizeof(char) * 1);
	map->vp_map[0] = '\0';
	map->height = 0;
	while (s != NULL)
	{
		map->vp_map = ft_strjoin(map->vp_map, s);
		map->map = ft_strjoin(map->map, s);
		free(s);
		map->height++;
		s = get_next_line(fd);
	}
	map->maptwo = ft_split(map->map, '\n');
	map->vp_maptwo = ft_split(map->map, '\n');
	map->vp_fe_maptwo = ft_split(map->map, '\n');
}

int	check_map(t_data *map)
{
	int	a;
	int	b;
	int	mc_line;

	a = 0;
	b = 0;
	mc_line = 0;
	while (mc_line < map->height)
	{
		b = map_line(map->maptwo[mc_line], mc_line, map);
		if (b == 0)
			return (0);
		a = map_length(map->maptwo[0]);
		if (a != map_length(map->maptwo[mc_line]))
			return (0);
		mc_line++;
	}
	return (1);
}

int	map_line(char *s, int mc_line, t_data *map)
{
	int	a;

	a = 0;
	if (mc_line == 0 || mc_line == map->height - 1)
	{
		a = 0;
		while (s[a] != '\0')
		{
			if (s[a] != '1')
				return (0);
			a++;
		}
	}
	else if (mc_line < map->height - 1)
	{
		if (s[0] != '1' || s[map->width - 1] != '1')
			return (0);
	}
	return (1);
}

int	map_length(char *s)
{
	int		a;

	a = 0;
	while (s[a] != '\n' && s[a] != '\0')
		a++;
	return (a);
}

int	map_name(char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	if (s[a - 3] == 'b' && s[a - 2] == 'e' && s[a - 1] == 'r'
		&& s[a] == '\0')
		return (1);
	return (0);
}
