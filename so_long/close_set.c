/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:43:44 by hseven            #+#    #+#             */
/*   Updated: 2022/10/01 12:22:51 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->vp_maptwo[i]);
		free(data->maptwo[i]);
		free(data->vp_fe_maptwo[i]);
		i++;
	}
	free(data->vp_maptwo);
	free(data->maptwo);
	free(data->vp_fe_maptwo);
	exit(0);
}

void	free_all(t_data *data)
{
	mlx_destroy_window(data->adr, data->pen);
	free (data->img);
	free(data->map);
	free(data->vp_map);
	free_map(data);
}
