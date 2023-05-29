/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:31:05 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/22 11:45:11 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = readtext(fd, stash);
	if (!stash)
		return (NULL);
	line = split(stash);
	stash = ft_memcpygnl(stash);
	return (line);
}

char	*readtext(int fd, char *stash)
{
	char	*buf;
	int		n;

	n = 0;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (findnewline(stash) != 1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			if (stash)
				free(stash);
			return (free(buf), NULL);
		}
		if (n == 0)
			break ;
		buf[n] = '\0';
		stash = ft_strjoingnl(stash, buf);
		if (stash == NULL)
			return (free(buf), NULL);
	}
	free(buf);
	return (stash);
}

int	findnewline(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoingnl(char *stash, char *buf)
{
	char	*str;

	if (!stash)
	{
		stash = malloc(sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buf)
		return (0);
	str = malloc(sizeof(char) * ((ft_strlengnl(stash)
					+ ft_strlengnl(buf) + 1)));
	if (!str)
		return (NULL);
	str = ft_strcpy(stash, buf, str);
	free(stash);
	return (str);
}

char	*ft_strcpy(char *stash, char *buf, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (stash[i] != '\0')
	{
		str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buf[j] != '\0')
	{
		str[i] = buf[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
