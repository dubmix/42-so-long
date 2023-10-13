/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:11:40 by pdelanno          #+#    #+#             */
/*   Updated: 2023/01/18 16:54:10 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s)
{
	char	*str2;
	int		index;
	int		length;

	index = 0;
	length = ft_strlen(s);
	str2 = (char *)malloc(sizeof(char) * (length + 1));
	if (str2 == 0)
		return (NULL);
	while (s[index] != '\0')
	{
		str2[index] = s[index];
		index++;
	}
	str2[index] = '\0';
	return (str2);
}
