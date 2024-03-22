/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_thousand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:17:35 by seonggek          #+#    #+#             */
/*   Updated: 2023/09/12 01:02:09 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	check_thousand(int size, char *key)
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

void	print_thousand(int size, t_dict *list)
{
	int	i;

	if (size == 1)
		return ;
	i = 0;
	while (list[i].key_len != size || check_thousand(size, list[i].key) == 0)
		i++;
	write(1, " ", 1);
	print_num(list[i].value);
}