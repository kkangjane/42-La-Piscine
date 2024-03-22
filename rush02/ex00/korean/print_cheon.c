/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:02:18 by seonggek          #+#    #+#             */
/*   Updated: 2023/09/10 11:57:48 by seonggek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	check_4(char *str, struct s_dict *list, int size)
{
	int	i;

	if (size == 4)
	{
		if (*str != '0')
		{
			if (*str != '1')
			{
				i = 0;
				while (list[i].key_len != 1 || *(list[i].key) != *str)
					i++;
				print_num(list[i].value);
			}
			i = 0;
			while (list[i].key_len != 4 || list[i].key[0] != '1'
				|| list[i].key[1] != '0' || list[i].key[2] != '0'
				|| list[i].key[3] != '0')
				i++;
			print_num(list[i].value);
		}
		return (1);
	}
	return (0);
}

int	check_3(char *str, struct s_dict *list, int size)
{
	int	i;

	if (size == 3)
	{
		if (*str != '0')
		{
			if (*str != '1')
			{
				i = 0;
				while (list[i].key_len != 1 || *(list[i].key) != *str)
					i++;
				print_num(list[i].value);
			}
			i = 0;
			while (list[i].key_len != 3 || list[i].key[0] != '1'
				|| list[i].key[1] != '0' || list[i].key[2] != '0')
				i++;
			print_num(list[i].value);
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
	if (*str != '0')
	{
		if (*str != '1')
		{
			i = 0;
			while (list[i].key_len != 1 || *(list[i].key) != *str)
				i++;
			print_num(list[i].value);
		}
		i = 0;
		while (list[i].key_len != 2 || list[i].key[0] != '1'
			|| list[i].key[1] != '0')
			i++;
		print_num(list[i].value);
	}
	return (1);
}

int	check_1(char *str, struct s_dict *list, int size, int left)
{
	int	i;

	if (size != 1)
		return (0);
	if (left == 5 && *str == '1')
		return (1);
	i = 0;
	while (list[i].key_len != 1 || *(list[i].key) != *str)
		i++;
	print_num(list[i].value);
	return (1);
}

void	print_cheon(char *str, struct s_dict *list, int cur_size, int left_size)
{
	if (check_1(str, list, cur_size, left_size) == 1)
		return ;
	if (check_4(str, list, cur_size) == 1)
	{
		cur_size--;
		str++;
	}
	if (check_3(str, list, cur_size) == 1)
	{
		cur_size--;
		str++;
	}
	if (check_2(str, list, cur_size) == 1)
	{
		cur_size--;
		str++;
		if (*str == '0')
			return ;
	}
	if (check_1(str, list, cur_size, 0) == 1)
		return ;
	return ;
}
