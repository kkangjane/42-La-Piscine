/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:51:50 by jae-kang          #+#    #+#             */
/*   Updated: 2023/08/31 11:56:34 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_base(char *base)
{
	int	i;
	int	ascci[128];

	i = 0;
	while (i < 128)
		ascci[i++] = 0;
	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		if (ascci[(int) base[i]] == 1)
			return (0);
		ascci[(int) base[i]] = 1;
		i++;
	}
	return (1);
}

int	check_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	change_from_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_result(char *base, char *str, int minus, int i)
{
	int	result;
	int	mul;
	int	base_type;

	base_type = 0;
	while (base[base_type])
		base_type++;
	mul = 1;
	result = 0;
	while (check_base(base, str[i]))
	{
		if (minus == 1)
			result += change_from_base(str[i], base) * mul;
		else
			result -= change_from_base(str[i], base) * mul;
		mul *= base_type;
		i--;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	i;
	int	minus;
	int	mul;

	mul = 1;
	result = 0;
	minus = 1;
	if (is_base(base) == 0)
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (check_base(base, str[i]))
		i++;
	i--;
	result = ft_result(base, str, minus, i);
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
	char str[] = "    \t  \v  --++-+--bdcev1d";

	char base[] = "abcdefgh";
	
	printf("%d\n", ft_atoi_base(str, base)); 
}
*/
