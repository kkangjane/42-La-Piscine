/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:49:21 by jae-kang          #+#    #+#             */
/*   Updated: 2023/08/30 16:53:49 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while (i * i <= (unsigned int) nb)
	{
		if ((unsigned int)nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int main(void)
{
	int nb;

	nb = 2147483647;
	printf("%d: %d\n", nb, ft_is_prime(nb));
	nb = 8;
	printf("%d: %d\n", nb, ft_is_prime(nb));
	nb = 11;
	printf("%d: %d\n", nb, ft_is_prime(nb));
}
*/