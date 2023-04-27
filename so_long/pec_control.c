/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pec_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:45:26 by hseven            #+#    #+#             */
/*   Updated: 2022/09/30 13:40:36 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pec_check(t_data *data)
{
	int	a;
	int	e;
	int	p;
	int	c;

	c = ft_strchr(data->map, 'C');
	e = ft_strchr(data->map, 'E');
	p = ft_strchr(data->map, 'P');
	if (p != 1 || e != 1 || c == 0)
		return (0);
	a = 0;
	while (data->map[a] != '\0')
	{
		if (data->map[a] != 'E' && data->map[a] != 'C' && data->map[a] != 'P'
			&& data->map[a] != '1' && data->map[a] != '0'
			&& data->map[a] != '\n')
			return (0);
		a++;
	}
	data->coin = c;
	return (1);
}

char	**validpath_for_exit(char **str, int y, int x)
{
	if (str[y][x - 1] == '0' || str[y][x - 1] == 'C' || str[y][x - 1] == 'E')
	{
		str[y][x - 1] = '2';
		validpath_for_exit(str, y, x - 1);
	}
	if (str[y][x + 1] == '0' || str[y][x + 1] == 'C' || str[y][x + 1] == 'E')
	{	
		str[y][x + 1] = '2';
		validpath_for_exit(str, y, x + 1);
	}
	if (str[y - 1][x] == '0' || str[y - 1][x] == 'C' || str[y - 1][x] == 'E')
	{
		str[y - 1][x] = '2';
		validpath_for_exit(str, y - 1, x);
	}
	if (str[y + 1][x] == '0' || str[y + 1][x] == 'C' || str[y + 1][x] == 'E')
	{
		str[y + 1][x] = '2';
		validpath_for_exit(str, y + 1, x);
	}
	return (str);
}

int	validpath_x(char **str, int height, int width)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (height > y)
	{
		x = 1;
		while (width > x)
		{
			if (str[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	validpath_x_v2(char **str, int height, int width)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (height > y)
	{
		x = 1;
		while (width > x)
		{
			if (str[y][x] == 'C' || str[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

char	**validpath(char **str, int y, int x)
{
	if (str[y][x - 1] == '0' || str[y][x - 1] == 'C')
	{
		str[y][x - 1] = '2';
		validpath(str, y, x - 1);
	}
	if (str[y][x + 1] == '0' || str[y][x + 1] == 'C')
	{	
		str[y][x + 1] = '2';
		validpath(str, y, x + 1);
	}
	if (str[y - 1][x] == '0' || str[y - 1][x] == 'C')
	{
		str[y - 1][x] = '2';
		validpath(str, y - 1, x);
	}
	if (str[y + 1][x] == '0' || str[y + 1][x] == 'C')
	{
		str[y + 1][x] = '2';
		validpath(str, y + 1, x);
	}
	return (str);
}
