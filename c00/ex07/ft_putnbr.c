/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:05:08 by jae-kang          #+#    #+#             */
/*   Updated: 2023/08/24 17:34:15 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_size(int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_ten(int size)
{
	int	ten;
	int	i;

	ten = 1;
	i = 1;
	while (i < size)
	{
		ten *= 10;
		i++;
	}
	return (ten);
}

void	ft_positive_putnbr(int nb, int size)
{
	int		div;
	char	c;

	div = ft_ten(size);
	while (div >= 1)
	{
		c = '0' + nb / div;
		write(1, &c, 1);
		nb %= div;
		div /= 10;
	}
}

void	ft_putnbr(int nb)
{
	int	size;

	if (nb == 0)
		write(1, "0", 1);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		size = ft_size(nb);
		ft_positive_putnbr(nb, size);
	}
}
