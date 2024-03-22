/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:02:18 by seonggek          #+#    #+#             */
/*   Updated: 2023/09/12 00:36:00 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	print_num(char *list)
{
	while (*list)
		write(1, list++, 1);
}

int	check_3(char *str, struct s_dict *list, int size)
{
	int	i;
	//132일 때
	if (size == 3)
	{
		if (*str != '0')
		{
			i = 0;
			//one
			while (list[i].key_len != 1 || *(list[i].key) != *str)
				i++;
			print_num(list[i].value);
			write(1, " ", 1);
			i = 0;
			//hundred
			while (list[i].key_len != 3 || list[i].key[0] != '1'
				|| list[i].key[1] != '0' || list[i].key[2] != '0')
				i++;
			print_num(list[i].value);
			//만약 끝이 00이면 and 출력 안 하고 끝
			if (*(str + 1) == '0' && *(str + 2) == '0')
				return (1);
			write (1, " and ", 5);
		}
		return (1);
	}
	return (0);
}

int	check_2(char *str, struct s_dict *list, int size)
{
	int	i;

	if (size != 2)
		return (0);
	i = 0;
	//13이면 특별한 경우니까 thirteen을 출력
	if (*str == '1')
	{
		while (list[i].key_len != 2 || list[i].key[0] != '1'
			|| list[i].key[1] != *(str + 1))
			i++;
		print_num(list[i].value);
	}
	//아니고 시작이 0이 아니면 43이런거니까 
	else if (*str != '0')
	{
		//fourty
		while (list[i].key_len != 2 || list[i].key[0] != *str
			|| list[i].key[1] != '0')
			i++;
		print_num(list[i].value);
		if (*(str + 1) == '0')
			return (1);
		write(1, "-", 1);
	}
	return (1);
}

int	check_1(char *str, struct s_dict *list, int size)
{
	int	i;

	if (size != 1)
		return (0);
	i = 0;
	while (list[i].key_len != 1 || *(list[i].key) != *str)
		i++;
	print_num(list[i].value);
	return (1);
}

void	print_hundreds(char *str, struct s_dict *list, int size)
{
	if (check_1(str, list, size) == 1)
		return ;
	if (check_3(str, list, size) == 1)
	{
		size--;
		str++;
	}
	if (check_2(str, list, size) == 1)
	{
		if (*str == '1')
			return ;
		size--;
		str++;
		if (*str == '0')
			return ;
	}
	if (check_1(str, list, size) == 1)
		return ;
	return ;
}
