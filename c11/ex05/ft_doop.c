/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:09:41 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/11 20:18:12 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	flag;

	i = 0;
	result = 0;
	flag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + flag * (str[i++] - '0');
	return (result);
}

void	ft_putnbr(int n)
{
	char		c[10];
	long long	nbr;
	int			i;

	nbr = (long long) n;
	i = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	while (1)
	{
		c[i++] = nbr % 10 + '0';
		nbr /= 10;
		if (nbr == 0)
			break ;
	}
	i--;
	while (i >= 0)
		write(1, &c[i--], 1);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (1);
	if (argv[2][0] == '+' && argv[2][1] == '\0')
		ft_putnbr(ft_atoi(argv[1]) + ft_atoi(argv[3]));
	else if (argv[2][0] == '-' && argv[2][1] == '\0')
		ft_putnbr(ft_atoi(argv[1]) - ft_atoi(argv[3]));
	else if (argv[2][0] == '*' && argv[2][1] == '\0')
		ft_putnbr(ft_atoi(argv[1]) * ft_atoi(argv[3]));
	else if (argv[2][0] == '/' && argv[2][1] == '\0')
	{
		if (ft_atoi(argv[3]) == 0)
			write(1, "Stop : division by zero\n", 24);
		else
			ft_putnbr(ft_atoi(argv[1]) / ft_atoi(argv[3]));
	}
	else if (argv[2][0] == '%' && argv[2][1] == '\0')
	{
		if (ft_atoi(argv[3]) == 0)
			write(1, "Stop : modulo by zero\n", 22);
		else
			ft_putnbr(ft_atoi(argv[1]) % ft_atoi(argv[3]));
	}
	else
		write(1, "0\n", 2);
	return (0);
}
