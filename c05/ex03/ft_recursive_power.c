/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:28:17 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/03 10:07:37 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>

int main(void)
{
	int nb = -4;
	int power = 3;
	printf("%d^%d: %d\n", nb, power, ft_recursive_power(nb, power));
	nb = 0;
	power = -2;
	printf("%d^%d: %d\n", nb, power, ft_recursive_power(nb, power));
	nb = 7;
	power = 5;
	printf("%d^%d: %d\n", nb, power, ft_recursive_power(nb, power));
	return 0;
}
*/
