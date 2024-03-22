/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:27:55 by jae-kang          #+#    #+#             */
/*   Updated: 2023/08/30 12:20:02 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_address(void *addr)
{
	int		address[16];
	long	ad;
	int		i;
	char	c;

	i = 15;
	ad = (long) addr;
	while (i >= 0)
	{
		address[i] = ad % 16;
		ad = ad / 16;
		i--;
	}
	i = 0;
	while (i < 16)
	{
		if (address[i] < 10)
			c = address[i] + '0';
		else
			c = address[i] + 'a' - 10;
		write(1, &c, 1);
		i++;
	}
	write(1, ":", 1);
}

void	ft_print_hex(void *addr, int size)
{
	int				i;
	unsigned char	*str;
	char			*c;

	i = 0;
	c = "0123456789abcdef";
	str = (unsigned char *) addr;
	while (i < size)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, &c[str[i] / 16], 1);
		write(1, &c[str[i] % 16], 1);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
}

void	ft_print_ch(void *addr, int size)
{
	char	c;
	char	*str;
	int		i;

	write(1, " ", 1);
	str = (char *) addr;
	i = 0;
	while (i < size)
	{
		c = str[i];
		if (c < ' ' || c > 127)
			c = '.';
		write(1, &c, 1);
		i++;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return ;
	while (i < size / 16 + 1)
	{
		if (i == size / 16)
		{
			if (size % 16 == 0)
				return ;
			ft_print_address(addr);
			ft_print_hex(addr, size % 16);
			ft_print_ch(addr, size % 16);
			write(1, "\n", 1);
			return ;
		}
		ft_print_address(addr);
		ft_print_hex(addr, 16);
		ft_print_ch(addr, 16);
		write(1, "\n", 1);
		addr += 16;
		i++;
	}
	write(1, "\n", 1);
}
