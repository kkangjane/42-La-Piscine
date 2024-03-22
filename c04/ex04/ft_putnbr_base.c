/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:30:03 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/08 18:45:51 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_base(char *base)
{
	int	i;
	int	board[128];

	i = 0;
	while (i < 128)
		board[i++] = 0;
	if (base[0] == 0 || base[1] == 0)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (board[(int) base[i]] == 1)
			return (0);
		board[(int) base[i]] = 1;
		i++;
	}
	return (1);
}

long long	ft_check_minus(long long n)
{
	if (n >= 0)
		return (n);
	write(1, "-", 1);
	return (-n);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			i;
	int			base_size;
	int			result[32];
	long long	n;

	if (is_base(base) == 0)
		return ;
	base_size = 0;
	while (base[base_size])
		base_size++;
	n = ft_check_minus((long long) nbr);
	if (n == 0)
		write(1, &base[0], 1);
	i = 0;
	while (n > 0)
	{
		result[i++] = n % base_size;
		n /= base_size;
	}
	i--;
	while (i >= 0)
		write(1, &base[result[i--]], 1);
}
