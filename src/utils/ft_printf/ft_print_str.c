/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <pdelanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:38:19 by pdelanno          #+#    #+#             */
/*   Updated: 2023/10/13 14:48:46 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		prc;

	prc = tab->prc;
	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		tab->totlen += write(1, "(null)", 6);
		return ;
	}
	if (tab->wdt && !tab->dash)
		ft_right_align(tab, ft_strlenprf(tab, str));
	sub_str(tab, prc, str);
	if (tab->wdt && tab->dash)
		ft_left_align(tab, ft_strlenprf(tab, str));
}

void	sub_str(t_print *tab, int prc, char *str)
{
	int	i;

	i = 0;
	if (prc > 0)
	{
		while (prc > 0 && str[i])
		{
			tab->totlen += write(1, &str[i], 1);
			prc -= 1;
			i++;
		}
	}		
	else
	{
		while (str[i])
		{
			tab->totlen += write(1, &str[i], 1);
			i++;
		}
	}
}
