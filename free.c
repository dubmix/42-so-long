/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:38:50 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/25 07:58:00 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freeall(t_data *data)
{
	mlx_destroy_image(data->mlx, data->background.xpm_ptr);
	mlx_destroy_image(data->mlx, data->wall.xpm_ptr);
	mlx_destroy_image(data->mlx, data->eeveefront.xpm_ptr);
	mlx_destroy_image(data->mlx, data->eeveeback.xpm_ptr);
	mlx_destroy_image(data->mlx, data->eeveeleft.xpm_ptr);
	mlx_destroy_image(data->mlx, data->eeveeright.xpm_ptr);
	mlx_destroy_image(data->mlx, data->exit.xpm_ptr);
	mlx_destroy_image(data->mlx, data->items.xpm_ptr);
	mlx_destroy_image(data->mlx, data->enemy.xpm_ptr);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_map(data);
	free(data);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->size_y / IMG_HEIGHT))
		free(data->map.map[i++]);
	free(data->map.map);
}
