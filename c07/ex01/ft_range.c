/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:49:38 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/03 19:44:50 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	size;

	if (min >= max)
		return (0);
	size = max - min;
	arr = (int *) malloc(size * 4);
	if (arr == NULL)
		return (0);
	i = 0;
	while (i <= size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>

int main(void)
{
	int	min = 1;
	int max = 3;
	int *arr;

	if (!(arr = ft_range(min, max)))
	{
		printf("malloc error");
		return (0);
	}
	int i = 0;
	while (i <= max - min)
		printf("%d ", arr[i++]);
	return (0);
}
*/
