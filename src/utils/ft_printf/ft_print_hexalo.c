/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexalo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <pdelanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:45:35 by pdelanno          #+#    #+#             */
/*   Updated: 2023/10/13 14:48:39 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_print_hexalo(t_print *tab)
{
	unsigned int	nb;
	char			*base;
	char			tmp[16];
	int				i;

	nb = va_arg(tab->args, unsigned int);
	base = "0123456789abcdef";
	i = sub_hexa(tab, base, tmp, nb);
	if (tab->hashtag)
		tab->wdt -= 2;
	if (tab->wdt && !tab->dash)
		ft_right_align(tab, ft_strlenprf(tab, tmp));
	if (tab->hashtag)
		tab->totlen += write(1, "0x", 2);
	if (tab->prc)
		ft_precision(tab, ft_strlenprf(tab, tmp));
	while (--i >= 0)
		tab->totlen += write(1, &tmp[i], 1);
	if (tab->wdt && tab->dash)
		ft_left_align(tab, ft_strlenprf(tab, tmp));
}

int	sub_hexa(t_print *tab, char *base, char *tmp, unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		tab->totlen += write(1, "0", 1);
	while (nb > 0)
	{
		tmp[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	return (i);
}
