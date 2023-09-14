/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:08:46 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/01 18:06:57 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_ok(int *col, int pushed)
{
	int	i;

	i = 0;
	while (i < pushed)
	{
		if (col[i] == col[pushed])
			return (0);
		if (i - pushed == col[i] - col[pushed])
			return (0);
		if (i - pushed == col[pushed] - col[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_recursive(int *col, int to_push, int *pointer)
{
	int		i;
	char	c;

	if (to_push >= 10)
	{
		i = 0;
		while (i < 10)
		{
			c = col[i++] + '0';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
		*pointer = *pointer + 1;
		return ;
	}
	i = 0;
	while (i < 10)
	{
		col[to_push] = i;
		if (ft_ok(col, to_push))
			ft_recursive(col, to_push + 1, pointer);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	col[10];
	int	i;
	int	result;
	int	*pointer;

	i = 0;
	pointer = &result;
	ft_recursive(col, 0, pointer);
	return (result);
}

/*
#include <stdio.h>
int main(void)
{
	int result = ft_ten_queens_puzzle();
	return 0;
}
*/
