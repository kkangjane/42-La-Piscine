/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:30:50 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/07 17:40:42 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comma(int C[], int n);
void	ft_print_numarray(int C[], int n);
void	ft_recur(int index, int value, int C[], int n);

void	ft_print_combn(int n)
{
	int	c[9];

	ft_recur(0, 0, c, n);
}

void	ft_recur(int index, int value, int C[], int n)
{
	if (index == n)
	{
		ft_print_numarray(C, n);
		return ;
	}
	if (value == 10)
		return ;
	C[index] = value;
	ft_recur(index + 1, value + 1, C, n);
	ft_recur(index, value + 1, C, n);
}

void	ft_print_comma(int C[], int n)
{
	int	i;
	int	cmp;
	int	result;

	result = 1;
	i = n - 1;
	cmp = 9;
	while (i >= 0)
	{
		if (C[i] != cmp)
			result = 0;
		i--;
		cmp--;
	}
	if (result == 0)
		write(1, ", ", 2);
}

void	ft_print_numarray(int C[], int n)
{
	char	c;
	int		i;

	i = 0;
	while (i < n)
	{
		c = C[i] + '0';
		write(1, &c, 1);
		i++;
	}
	ft_print_comma(C, n);
}
