/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:41:12 by jae-kang          #+#    #+#             */
/*   Updated: 2023/08/30 17:04:32 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	result;

	result = 0;
	if (nb <= 0)
		return (0);
	while (result * result <= (unsigned int)nb)
	{
		if (result * result == (unsigned int)nb)
			return (result);
		result++;
	}	
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	printf("sqrt(%d): %d\n", 9, ft_sqrt(9));
	printf("sqrt(%d): %d\n", 25, ft_sqrt(25));
	printf("sqrt(%d): %d\n", 2147483647, ft_sqrt(2147483647));
}
*/