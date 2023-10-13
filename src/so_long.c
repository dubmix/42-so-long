/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:20:43 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/25 07:59:26 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		fd;

	data = malloc(sizeof(t_data));
	if (argc != 2)
	{
		ft_printf("Error\nThere are more or less than 2 arguments\n");
		free(data);
		exit(EXIT_FAILURE);
	}
	ft_window_size(data, argv);
	fd = open(argv[1], O_RDONLY);
	data->map.map = ft_convert_input(fd);
	ft_init(data);
	ft_check_borders(data);
	ft_check_content(data);
	flood_fill(data);
	ft_printf("Help Eevee collect all the pokeballs and find her trainer!\n");
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,
			data->size_x, data->size_y, "so_long");
	ft_init_imgs(data);
	ft_render_next_frame(data);
	mlx_loop(data->mlx);
	exit(EXIT_FAILURE);
}

int	ft_render_next_frame(t_data *data)
{
	ft_put_background(data);
	ft_create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("You gave up!\n");
	ft_freeall(data);
	exit(EXIT_SUCCESS);
}

void	ft_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("Nice!\n");
	ft_printf("You won in %d moves\n", data->counter);
	ft_freeall(data);
	exit(EXIT_SUCCESS);
}
