/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:53:43 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/25 08:01:05 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_borders(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y / IMG_HEIGHT))
	{
		if ((int)ft_strlen(data->map.map[y]) != data->size_x / IMG_WIDTH)
			ft_map_error("Error\nMap has to be rectangular\n", data);
		x = 0;
		while (x < (data->size_x / IMG_WIDTH))
		{
			if (data->map.map[y][x] != '0' && data->map.map[y][x] != '1'
				&& data->map.map[y][x] != 'C' && data->map.map[y][x] != 'P'
				&& data->map.map[y][x] != 'E' && data->map.map[y][x] != 'e')
				ft_map_error("Error\nMap is not valid\n", data);
			else if ((y == 0 || x == 0) && data->map.map[y][x] != '1')
				ft_map_error("Error\nMap must be surrounded by walls\n", data);
			else if ((y == (data->size_y / IMG_HEIGHT - 1)
					|| x == (data->size_x / IMG_WIDTH - 1))
				&& data->map.map[y][x] != '1')
				ft_map_error("Error\nMap must be surrounded by walls\n", data);
			x++;
		}
		y++;
	}
}

void	ft_check_content(t_data *data)
{
	int	y;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	data->map.items = 0;
	y = 0;
	while (data->map.map && data->map.map[y])
	{
		exit += ft_count_char(data->map.map[y], 'E');
		player += ft_count_char(data->map.map[y], 'P');
		data->map.items += ft_count_char(data->map.map[y], 'C');
		y++;
	}
	if (player != 1)
		ft_map_error("Error\nOne player is required\n", data);
	if (exit != 1)
		ft_map_error("Error\nOne exit is required\n", data);
	if (data->map.items == 0)
		ft_map_error("Error\nAt least one pokeball must be included\n", data);
}

int	check_valid_path(t_data *copy, int x, int y)
{
	if (copy->map.map[y][x] == '1' || copy->map.map[y][x] == 'e')
		return (0);
	if (copy->map.map[y][x] == 'E')
	{
		copy->map.valid_exit = 1;
		return (0);
	}
	copy->map.map[y][x] = '1';
	if (check_valid_path(copy, x, y + 1))
		return (1);
	if (check_valid_path(copy, x, y - 1))
		return (1);
	if (check_valid_path(copy, x + 1, y))
		return (1);
	if (check_valid_path(copy, x - 1, y))
		return (1);
	return (0);
}

void	flood_fill(t_data *data)
{
	t_data	copy;
	int		i;

	copy.map.map = malloc((data->size_y / IMG_HEIGHT) * sizeof(char *));
	if (!copy.map.map)
		ft_map_error("Error\nMemory allocation failed\n", data);
	i = 0;
	while (i < (data->size_y / IMG_HEIGHT))
	{
		copy.map.map[i] = ft_strdup(data->map.map[i]);
		i++;
	}
	copy.map.valid_exit = 0;
	copy.p_x = data->p_x;
	copy.p_y = data->p_y;
	copy.size_y = data->size_y;
	check_valid_path(&copy, copy.p_x, copy.p_y);
	if (copy.map.valid_exit == 0)
	{
		ft_free_map(&copy);
		ft_map_error("Error\nValid path not found\n", data);
	}
	ft_free_map(&copy);
}

void	ft_map_error(char *str, t_data *data)
{
	ft_printf("%s", str);
	ft_free_map(data);
	free(data);
	exit(EXIT_FAILURE);
}
