/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:39:55 by hseven            #+#    #+#             */
/*   Updated: 2022/10/01 13:33:09 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(t_data *data, char *s)
{
	if (data->fd < 0)
	{
		ft_printf("Map couldn't open!");
		free_map(data);
		return (0);
	}
	if (check_map(data) == 0)
	{
		ft_printf("Map isn't useable!");
		free_map(data);
		return (0);
	}
	if (pec_check(data) == 0)
	{	
		ft_printf("Your map hasn't 'E,C,P' or has wrong character(s)!");
		free_map(data);
		return (0);
	}
	if (map_name(s) == 0)
	{
		ft_printf("Your map's extention must be '.ber' !");
		free_map(data);
		return (0);
	}
	return (1);
}

int	map_checker_two(t_data *data)
{
	wisp(data);
	data->vp_fe_maptwo = validpath_for_exit(data->vp_fe_maptwo,
			data->p_posy, data->p_posx);
	data->vp_maptwo = validpath(data->vp_maptwo, data->p_posy, data->p_posx);
	if (validpath_x(data->vp_maptwo, data->height, data->width) == 0)
	{
		ft_printf("Your map should be able to finish!");
		free_map(data);
		return (0);
	}
	if (validpath_x_v2(data->vp_fe_maptwo, data->height, data->width) == 0)
	{
		ft_printf("Your map should be able to finish!");
		free_map(data);
		return (0);
	}
	return (1);
}

int	key_control(int keycode, t_data *data)
{
	if (keycode == 2)
		walk_right(data, data->p_posy, data->p_posx);
	if (keycode == 13)
		walk_up(data, data->p_posy, data->p_posx);
	if (keycode == 1)
		walk_down(data, data->p_posy, data->p_posx);
	if (keycode == 0)
		walk_left(data, data->p_posy, data->p_posx);
	if (keycode == 53 || keycode == 17)
		free_all(data);
	return (0);
}

int	key_exit(t_data *data)
{
	free_all(data);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = malloc(sizeof(t_data) * 1);
		data->fd = open(argv[1], O_RDONLY);
		data->collect_coin = 0;
		data->coin = 0;
		data->score = 0;
		data->foot_step = 0;
		read_map(data->fd, data);
		if (map_checker(data, argv[1]) == 0 || map_checker_two(data) == 0)
			return (0);
		data->adr = mlx_init();
		data->pen = mlx_new_window(data->adr, data->width * 64,
				data->height * 64, "so_long");
		put_score(data);
		add_image(data);
		put_map(data);
		mlx_hook(data->pen, 17, 0, key_exit, data);
		mlx_hook(data->pen, 2, 1L << 0, key_control, data);
		mlx_loop(data->adr);
		return (0);
	}
	return (0);
}
