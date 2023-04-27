/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:43:44 by hseven            #+#    #+#             */
/*   Updated: 2022/10/01 14:00:27 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(int y, int x, t_data *data)
{
	if (data->maptwo[y][x] == '1')
		mlx_put_image_to_window(data->adr, data->pen,
			data->img[2], data->s_posx, data->s_posy);
	else if (data->maptwo[y][x] == '0')
		mlx_put_image_to_window(data->adr, data->pen,
			data->img[0], data->s_posx, data->s_posy);
	else if (data->maptwo[y][x] == 'E')
		mlx_put_image_to_window(data->adr, data->pen,
			data->img[1], data->s_posx, data->s_posy);
	else if (data->maptwo[y][x] == 'C')
		mlx_put_image_to_window(data->adr, data->pen,
			data->img[4], data->s_posx, data->s_posy);
	else if (data->maptwo[y][x] == 'P')
		mlx_put_image_to_window(data->adr, data->pen,
			data->img[3], data->s_posx, data->s_posy);
	put_score(data);
}

void	put_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->s_posy = 0;
	while (y < data->height)
	{
		data->s_posx = 0;
		x = 0;
		while (x <= data->width)
		{
			mlx_put_image_to_window(data->adr, data->pen,
				data->img[0], data->s_posx, data->s_posy);
			data->s_posx += 64;
			x++;
		}
		data->s_posy += 64;
		y++;
	}
}

void	put_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	put_background(data);
	if (data->collect_coin == data->coin)
		data->img[1] = mlx_xpm_file_to_image(data->adr,
				DO_FT, &data->imgx, &data->imgy);
	data->s_posy = 0;
	while (y < data->height)
	{
		data->s_posx = 0;
		x = 0;
		while (x <= data->width)
		{
			put_image(y, x, data);
			data->s_posx += 64;
			x++;
		}
		data->s_posy += 64;
		y++;
	}
}

void	add_image(t_data *data)
{
	data->s_posx = 0;
	data->s_posy = 0;
	data->img = ft_calloc_gnl(5, sizeof(void *));
	data->img[0] = mlx_xpm_file_to_image(data->adr,
			BG_FT, &data->imgx, &data->imgy);
	data->img[1] = mlx_xpm_file_to_image(data->adr,
			DR_FT, &data->imgx, &data->imgy);
	data->img[2] = mlx_xpm_file_to_image(data->adr,
			WL_FT, &data->imgx, &data->imgy);
	data->img[3] = mlx_xpm_file_to_image(data->adr,
			CHDO_FT, &data->imgx, &data->imgy);
	data->img[4] = mlx_xpm_file_to_image(data->adr,
			CO_FT, &data->imgx, &data->imgy);
}

void	put_score(t_data *data)
{
	char	*score;
	char	*foot_step;

	foot_step = ft_itoa(data->foot_step);
	score = ft_itoa(data->score);
	mlx_string_put(data->adr, data->pen, 20, 20, 0xFFFFFFF, "Score = ");
	mlx_string_put(data->adr, data->pen, 80, 20, 0xFFFFFFF, score);
	mlx_string_put(data->adr, data->pen, 20, 40, 0xFFFFFFF, "Foot Step = ");
	mlx_string_put(data->adr, data->pen, 104, 40, 0xFFFFFFF, foot_step);
	free(score);
}
