/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:21:57 by pdelanno          #+#    #+#             */
/*   Updated: 2023/04/10 22:22:03 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*split(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	line = malloc(sizeof(char) * ft_strlengnl(stash) + 1);
	if (!line)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_memcpygnl(char *stash)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlengnl(stash) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free(stash);
	return (str);
}

int	ft_strlengnl(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}	
	return (i);
}
