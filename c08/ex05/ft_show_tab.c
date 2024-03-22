/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:42:56 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/11 14:23:21 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str);
void	ft_putnbr(int nb);

void	ft_show_tab(t_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
		i++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	ft_putnbr(int nbr)
{
	int			i;
	int			result[11];
	char		c;
	long long	n;

	n = nbr;
	i = 0;
	while (1)
	{
		result[i] = n % 10;
		n /= 10;
		i++;
		if (n == 0)
			break ;
	}
	i--;
	while (i >= 0)
	{
		c = result[i] + '0';
		write(1, &c, 1);
		i--;
	}
	write(1, "\n", 1);
}
