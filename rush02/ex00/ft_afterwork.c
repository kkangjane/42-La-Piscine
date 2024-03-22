/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afterwork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:30:21 by ska               #+#    #+#             */
/*   Updated: 2023/09/12 01:50:18 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	calculate_valuesize(char *str)
{
	int	flag;
	int	count;

	flag = 0;
	while (*str == ' ')
		str++;
	count = 0;
	while (*str)
	{
		if (*str < 32 || *str > 126)
			return (-1);
		if (*str == ' ')
			flag = 1;
		else if (flag)
		{
			count += 2;
			flag = 0;
		}
		else
			count++;
		str++;
	}
	return (count + 1);
}

int	is_additional_duplicate(t_new_keys **nkeys, char *dest)
{
	t_new_keys	*prev;
	t_new_keys	*cur;
	int			j;

	cur = *nkeys;
	if (!cur)
	{
		*nkeys = get_new_keys(dest);
		return (0);
	}
	while (cur)
	{
		if (cur->key_len == ft_strlen(dest))
		{
			j = 0;
			while (j < cur->key_len && cur->key[j] == dest[j])
				j++;
			if (j == cur->key_len)
				return (1);
		}
		prev = cur;
		cur = cur->next;
	}
	prev->next = get_new_keys(dest);
	return (0);
}

int	examine(t_dict *mele, t_new_keys **new_keys, char **ret_dest)
{
	char	*dest;

	if (ft_strlen(mele->key) == 0 && ft_strlen(mele->value) == 0)
		return (1);
	dest = copy_key(mele->key);
	if (!dest)
		return (-1);
	if (!is_in_initial(dest))
	{
		if (is_additional_duplicate(new_keys, dest))
		{
			free(dest);
			return (-1);
		}
		if (calculate_valuesize(mele->value) == 1)
			return (-1);
		return (1);
	}
	*ret_dest = dest;
	return (0);
}

int	insert_dest(char *dest, t_dict list[], int lis_len, char *value)
{
	if (!check_unique(dest, list, lis_len))
	{
		free(dest);
		return (-1);
	}
	list[lis_len].key = dest;
	list[lis_len].key_len = ft_strlen(dest);
	list[lis_len].value = copy_value(value);
	if (!list[lis_len].value)
		return (-1);
	return (0);
}

int	after_work(t_dict *mlist, t_dict list[], int malloc_size)
{
	int			idx;
	int			list_num;
	t_new_keys	*new_keys;
	char		*dest;
	int			flag;

	idx = 0;
	list_num = 0;
	new_keys = 0;
	init_list(list);
	while (idx < malloc_size)
	{
		flag = examine(&mlist[idx], &new_keys, &dest);
		if (flag == 1 && ++idx)
			continue ;
		else if (flag == -1)
			break ;
		flag = insert_dest(dest, list, list_num++, mlist[idx++].value);
		if (flag == -1)
			break ;
	}
	free_new_keys(new_keys);
	if (flag == -1)
		return (-1);
	return (list_num == 41);
}
