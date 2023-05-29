/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:02:47 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/22 10:51:34 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map(t_data *data)
{
	data->map.x = 0;
	data->map.y = 0;
	while (data->map.y < data->size_y / IMG_HEIGHT)
	{
		if (data->map.map[data->map.y][data->map.x] == 'P')
			ft_put_player(data);
		else if (data->map.map[data->map.y][data->map.x] == '1')
			mlx_put_image_to_window(data->mlx, data->win, data->wall.xpm_ptr,
				(data->map.x * IMG_WIDTH), (data->map.y * IMG_HEIGHT));
		else if (data->map.map[data->map.y][data->map.x] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, data->items.xpm_ptr,
				(data->map.x * IMG_WIDTH), (data->map.y * IMG_HEIGHT));
		else if (data->map.map[data->map.y][data->map.x] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, data->exit.xpm_ptr,
				(data->map.x * IMG_WIDTH), (data->map.y * IMG_HEIGHT));
		ft_create_map_bonus(data);
		if (data->map.x < (data->size_x / IMG_WIDTH))
			data->map.x++;
		else
		{
			data->map.y++;
			data->map.x = 0;
		}
	}
}

void	ft_create_map_bonus(t_data *data)
{
	if (data->map.map[data->map.y][data->map.x] == 'e')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy.xpm_ptr,
			(data->map.x * IMG_WIDTH), (data->map.y * IMG_HEIGHT));
}

void	ft_put_player(t_data *data)
{
	data->p_x = data->map.x;
	data->p_y = data->map.y;
	mlx_put_image_to_window(data->mlx, data->win, data->eeveefront.xpm_ptr,
		(data->p_x * IMG_WIDTH), (data->p_y * IMG_HEIGHT));
}

void	ft_put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->background.xpm_ptr, x, y);
			x += IMG_WIDTH;
		}
		y += IMG_HEIGHT;
	}
}
