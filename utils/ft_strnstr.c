/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:14:29 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/18 10:14:34 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && i + j < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
