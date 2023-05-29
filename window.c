/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:02:32 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/22 11:55:54 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_size(t_data *data, char **argv)
{
	int	fd;

	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		printf("Error\nMap has to be .ber\n");
		free(data);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nInvalid map path\n");
		free(data);
		exit(EXIT_FAILURE);
	}
	data->size_x = ft_line_len(fd) * IMG_WIDTH;
	data->size_y = ft_line_count(fd) * IMG_HEIGHT;
}

int	ft_line_len(int fd)
{
	char	buffer[1];
	int		len;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	len = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			len++;
		else
			break ;
	}
	return (len);
}

int	ft_line_count(int fd)
{
	char	*line;
	int		linecount;
	int		i;

	i = 0;
	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}
