/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:14:52 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/18 10:14:53 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		i;
	size_t	j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_strlen(s1))
		str[j++] = s1[i++];
	i = 0;
	while (j < (ft_strlen(s1) + ft_strlen(s2)))
		str[j++] = s2[i++];
	str[j] = '\0';
	free((void *)s1);
	free((void *)s2);
	return (str);
}
