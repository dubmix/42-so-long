/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:09:17 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/22 11:33:01 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_move(t_data *data, char pos, int dir)
{
	if (pos == 'y' && dir == UP)
		mlx_put_image_to_window(data->mlx, data->win, data->eeveeback.xpm_ptr,
			(data->p_x * IMG_WIDTH), (data->p_y * IMG_HEIGHT));
	if (pos == 'x' && dir == LEFT)
		mlx_put_image_to_window(data->mlx, data->win, data->eeveeleft.xpm_ptr,
			(data->p_x * IMG_WIDTH), (data->p_y * IMG_HEIGHT));
	if (pos == 'y' && dir == DOWN)
		mlx_put_image_to_window(data->mlx, data->win, data->eeveefront.xpm_ptr,
			(data->p_x * IMG_WIDTH), (data->p_y * IMG_HEIGHT));
	if (pos == 'x' && dir == RIGHT)
		mlx_put_image_to_window(data->mlx, data->win, data->eeveeright.xpm_ptr,
			(data->p_x * IMG_WIDTH), (data->p_y * IMG_HEIGHT));
}

void	ft_collect(t_data *data, char pos, int dir)
{
	data->collected++;
	data->map.map[data->p_y][data->p_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->background.xpm_ptr,
		(data->p_x * IMG_WIDTH), (data->p_y * IMG_HEIGHT));
	ft_player_move(data, pos, dir);
}

void	ft_move(t_data *data, char pos, int dir)
{
	mlx_put_image_to_window(data->mlx, data->win, data->background.xpm_ptr,
		(data->p_x * IMG_WIDTH), (data->p_y * IMG_HEIGHT));
	if (pos == 'y' && data->map.map[data->p_y + 1 * dir][data->p_x] != '1'
		&& (data->map.map[data->p_y + 1 * dir][data->p_x] != 'E'
		|| data->collected == data->map.items))
		data->p_y = data->p_y + 1 * dir;
	else if (pos == 'x' && data->map.map[data->p_y][data->p_x + 1 * dir] != '1'
		&& (data->map.map[data->p_y][data->p_x + 1 * dir] != 'E'
		|| data->collected == data->map.items))
		data->p_x = data->p_x + 1 * dir;
	else if (pos == 'y' && data->map.map[data->p_y + 1 * dir][data->p_x] == 'E'
		&& data->collected != data->map.items)
		ft_printf("Collect all pokeballs before leaving\n");
	else if (pos == 'x' && data->map.map[data->p_y][data->p_x + 1 * dir] == 'E'
		&& data->collected != data->map.items)
		ft_printf("Collect all pokeballs before leaving\n");
	ft_player_move(data, pos, dir);
	if (data->map.map[data->p_y][data->p_x] == 'C')
		ft_collect(data, pos, dir);
	ft_move_bonus(data);
	mlx_do_sync(data->mlx);
	ft_printf("You moved %d times.\n", ++data->counter);
}

void	ft_move_bonus(t_data *data)
{
	if (data->map.map[data->p_y][data->p_x] == 'e')
	{
		ft_printf("Eevee got scared and ran away!");
		mlx_destroy_window(data->mlx, data->win);
		ft_freeall(data);
		exit(EXIT_FAILURE);
	}
}
