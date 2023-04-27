/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:33:29 by hseven            #+#    #+#             */
/*   Updated: 2022/10/01 13:56:30 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walk_up(t_data *data, int y, int x)
{
	if (data->maptwo[y - 1][x] == 'E' && data->collect_coin == data->coin)
	{
		ft_printf("YOU WON!\nYour Score = %d\nYour Foot Step = %d",
			data->score, data->foot_step + 1);
		free_all(data);
		return (0);
	}
	else if (data->maptwo[y - 1][x] == 'C' || data->maptwo[y - 1][x] == '0')
	{
		if (data->maptwo[y - 1][x] == 'C')
		{
			data->collect_coin++;
			data->score += 50;
		}
		data->foot_step += 1;
		data->maptwo[y - 1][x] = 'P';
		data->maptwo[y][x] = '0';
		data->p_posy -= 1;
		mlx_clear_window(data->adr, data->pen);
		data->img[3] = mlx_xpm_file_to_image(data->adr,
				CHUP_FT, &data->imgx, &data->imgy);
		put_map(data);
	}
	return (0);
}

int	walk_down(t_data *data, int y, int x)
{
	if (data->maptwo[y + 1][x] == 'E' && data->collect_coin == data->coin)
	{
		ft_printf("YOU WON!\nYour score = %d\nYour Foot Step = %d",
			data->score, data->foot_step + 1);
		free_all(data);
		return (0);
	}
	else if (data->maptwo[y + 1][x] == 'C' || data->maptwo[y + 1][x] == '0')
	{
		if (data->maptwo[y + 1][x] == 'C')
		{
			data->collect_coin++;
			data->score += 50;
		}
		data->foot_step += 1;
		data->maptwo[y + 1][x] = 'P';
		data->maptwo[y][x] = '0';
		data->p_posy += 1;
		mlx_clear_window(data->adr, data->pen);
		data->img[3] = mlx_xpm_file_to_image(data->adr,
				CHDO_FT, &data->imgx, &data->imgy);
		put_map(data);
	}
	return (0);
}

int	walk_right(t_data *data, int y, int x)
{
	if (data->maptwo[y][x + 1] == 'E' && data->collect_coin == data->coin)
	{
		ft_printf("YOU WON!\nYour score = %d\nYour Foot Step = %d",
			data->score, data->foot_step + 1);
		free_all(data);
		return (0);
	}
	else if (data->maptwo[y][x + 1] == 'C' || data->maptwo[y][x + 1] == '0')
	{
		if (data->maptwo[y][x + 1] == 'C')
		{
			data->collect_coin++;
			data->score += 50;
		}
		data->foot_step += 1;
		data->maptwo[y][x + 1] = 'P';
		data->maptwo[y][x] = '0';
		data->p_posx += 1;
		mlx_clear_window(data->adr, data->pen);
		data->img[3] = mlx_xpm_file_to_image(data->adr,
				CHRI_FT, &data->imgx, &data->imgy);
		put_map(data);
	}
	return (0);
}

int	walk_left(t_data *data, int y, int x)
{
	if (data->maptwo[y][x - 1] == 'E' && data->collect_coin == data->coin)
	{
		ft_printf("YOU WON!\nYour score = %d\nYour Foot Step = %d",
			data->score, data->foot_step + 1);
		free_all(data);
		return (0);
	}
	else if (data->maptwo[y][x - 1] == 'C' || data->maptwo[y][x - 1] == '0')
	{
		if (data-> maptwo[y][x - 1] == 'C')
		{
			data->collect_coin++;
			data->score += 50;
		}
		data->foot_step += 1;
		data->maptwo[y][x - 1] = 'P';
		data->maptwo[y][x] = '0';
		data->p_posx -= 1;
		mlx_clear_window(data->adr, data->pen);
		data->img[3] = mlx_xpm_file_to_image(data->adr,
				CHLE_FT, &data->imgx, &data->imgy);
		put_map(data);
	}
	return (0);
}

int	wisp(t_data *data)
{
	int	x;

	x = 0;
	while (data->maptwo[x] != NULL)
	{
		if (ft_strchr(data->maptwo[x], 'P'))
		{
			data->p_posy = x;
			data->p_posx = wisp_strchr(data->maptwo[x], 'P');
			return (0);
		}
		x++;
	}
	return (0);
}
