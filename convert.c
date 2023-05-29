/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:00:51 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/22 09:45:49 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_convert_input(int fd)
{
	char	*last_line;
	char	*line;
	char	**map;

	last_line = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		last_line = ft_strjoin(last_line, line);
		line = get_next_line(fd);
	}
	free(line);
	map = ft_split(last_line, '\n');
	free(last_line);
	return (map);
}
