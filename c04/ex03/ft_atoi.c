/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:09:41 by jae-kang          #+#    #+#             */
/*   Updated: 2023/08/31 11:20:53 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	flag;
	int	i;
	int	result;

	i = 0;
	result = 0;
	flag = 1;
	while (ft_is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (flag == 1)
			result = result * 10 + (str[i] - '0');
		else
			result = result * 10 - (str[i] - '0');
		i++;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = "   \t\v  +++---+-00abcd";
	printf("%d\n", ft_atoi(str));
	return 0;
}
*/
