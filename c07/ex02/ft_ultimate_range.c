/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:54:03 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/06 10:08:52 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*arr;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	arr = (int *) malloc(4 * size);
	if (arr == NULL)
	{
		*range = NULL;
		return (-1);
	}
	*range = arr;
	i = 0;
	while (i < size)
		arr[i++] = min++;
	return (size);
}
/*
#include <stdio.h>
int main(void)
{
	int min = 5;
	int max = 10;
	int *tab;
	int **pointer;
	pointer = &tab;
	int size = ft_ultimate_range(pointer, min, max);
	printf("size: %d\n", size);
	for(int i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
	return 0;
}
*/
