/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:47:17 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/22 09:47:20 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == KEY_UP)
		ft_move(data, 'y', UP);
	else if (keycode == KEY_LEFT)
		ft_move(data, 'x', LEFT);
	else if (keycode == KEY_DOWN)
		ft_move(data, 'y', DOWN);
	else if (keycode == KEY_RIGHT)
		ft_move(data, 'x', RIGHT);
	if (data->map.map[data->p_y][data->p_x] == 'E')
		ft_win(data);
	return (0);
}
