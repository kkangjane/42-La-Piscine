/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:57:43 by ska               #+#    #+#             */
/*   Updated: 2023/09/10 12:02:47 by seonggek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	free_new_keys(t_new_keys *new_keys)
{
	t_new_keys	*prev;

	while (new_keys)
	{
		prev = new_keys;
		new_keys = new_keys->next;
		free(prev->key);
		free(prev);
	}
}

void	free_all(t_dict *malloced_list, int malloc_size, t_dict list[])
{
	int	i;

	i = 0;
	while (i < malloc_size)
	{
		if (malloced_list[i].key)
			free(malloced_list[i].key);
		if (malloced_list[i].value)
			free(malloced_list[i].value);
		i++;
	}
	free(malloced_list);
	i = 0;
	while (i < 25)
	{
		if (list[i].key)
			free(list[i].key);
		if (list[i].value)
			free(list[i].value);
		i++;
	}
}
