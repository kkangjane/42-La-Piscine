/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:57:15 by jae-kang          #+#    #+#             */
/*   Updated: 2023/08/30 17:00:22 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		i = 0;
		result = 1;
		while (i < power)
		{
			result *= nb;
			i++;
		}
	}
	return (result);
}

/*
#include <stdio.h>

int main(void)
{
	int nb = -4;
	int power = 3;
	printf("%d^%d: %d\n", nb, power, ft_iterative_power(nb, power));
	nb = 0;
	power = -2;
	printf("%d^%d: %d\n", nb, power, ft_iterative_power(nb, power));
	nb = 7;
	power = 5;
	printf("%d^%d: %d\n", nb, power, ft_iterative_power(nb, power));
	return 0;
}
*/