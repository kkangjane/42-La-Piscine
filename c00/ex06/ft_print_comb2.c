/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:54:39 by jae-kang          #+#    #+#             */
/*   Updated: 2023/08/24 12:04:36 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printnum(int n)
{
	char	c;

	if (n < 10)
	{
		c = '0' + n;
		ft_putchar('0');
		ft_putchar(c);
	}
	else
	{
		c = (n / 10) + '0';
		ft_putchar(c);
		c = (n % 10) + '0';
		ft_putchar(c);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			if (a != b)
			{
				ft_printnum(a);
				ft_putchar(' ');
				ft_printnum(b);
			}
			if (a != 98 || b != 99)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
