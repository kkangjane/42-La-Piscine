/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:50:23 by ska               #+#    #+#             */
/*   Updated: 2023/09/09 22:29:56 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	one_all_zero(char *nb, int len)
{
	int	i;

	if (nb[0] != '1')
		return (0);
	i = 1;
	while (i < len)
	{
		if (nb[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	check_unique(char *key, t_dict list[], int list_num)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (i < list_num)
	{
		if (list[i].key_len != len)
		{
			i++;
			continue ;
		}
		j = 0;
		while (j < len && list[i].key[j] == key[j])
			j++;
		if (j == len)
			return (0);
		i++;
	}
	return (1);
}

int	is_in_initial(char *nb)
{
	int	len;

	len = ft_strlen(nb);
	if (len <= 1)
		return (1);
	if (len == 2)
	{
		if (nb[0] == '1')
			return (1);
		if (nb[1] == '0')
			return (1);
		return (0);
	}
	if (len == 3 || (4 <= len && len <= 37 && len % 3 == 1))
	{
		if (one_all_zero(nb, len) == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}
