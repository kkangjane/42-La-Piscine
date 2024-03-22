/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_thousand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:17:35 by seonggek          #+#    #+#             */
/*   Updated: 2023/09/10 14:17:23 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	print_num(char *list)
{
	while (*list)
		write(1, list++, 1);
}

int	check_man(int size, char *key)
{
	int	i;

	i = 1;
	if (key[0] == '1')
	{
		while (key[i] == '0')
			i++;
		if (i == size)
			return (1);
	}
	return (0);
}

void	print_man(int size, t_dict *list)
{
	int	i;

	if (size == 1)
		return ;
	i = 0;
	while (list[i].key_len != size || check_man(size, list[i].key) == 0)
		i++;
	print_num(list[i].value);
}
