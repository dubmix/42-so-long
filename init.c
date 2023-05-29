/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:44:18 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/22 09:49:45 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *data)
{
	data->counter = 0;
	data->collected = 0;
	data->p_x = 1;
	data->p_y = 1;
}

void	ft_init_imgs(t_data *data)
{
	void	*mlx;

	mlx = data->mlx;
	data->eeveefront = ft_new_img(mlx, EEVEEFRONT_PATH);
	data->eeveeback = ft_new_img(mlx, EEVEEBACK_PATH);
	data->eeveeleft = ft_new_img(mlx, EEVEELEFT_PATH);
	data->eeveeright = ft_new_img(mlx, EEVEERIGHT_PATH);
	data->background = ft_new_img(mlx, BACKGROUND_PATH);
	data->wall = ft_new_img(mlx, WALL_PATH);
	data->items = ft_new_img(mlx, ITEMS_PATH);
	data->exit = ft_new_img(mlx, EXIT_PATH);
	data->enemy = ft_new_img(mlx, ENEMY_PATH);
}

t_img	ft_new_img(void *mlx, char *path)
{
	t_img	img;

	img.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	if (img.xpm_ptr == NULL)
	{
		ft_printf("Error\nAt least one image could not be loaded\n");
		exit(EXIT_FAILURE);
	}
	return (img);
}
