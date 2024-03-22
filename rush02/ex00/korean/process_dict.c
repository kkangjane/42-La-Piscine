/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:02:10 by ska               #+#    #+#             */
/*   Updated: 2023/09/10 12:04:47 by seonggek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	init_list(t_dict list[])
{
	int	i;

	i = 0;
	while (i < 25)
	{
		list[i].key = 0;
		list[i].key_len = 0;
		list[i].value = 0;
		i++;
	}
}

void	process(char *str, char *filename)
{
	t_dict			list[25];
	t_dict			*malloced_list;
	t_char_sizes	*sizes;
	int				linenumber;

	linenumber = get_linenumber(filename);
	if (linenumber < 0)
		return (write_dict_error());
	sizes = (t_char_sizes *)malloc(sizeof(t_char_sizes) * linenumber);
	if (get_char_sizes(sizes, filename) < 0)
	{
		free(sizes);
		return (write_dict_error());
	}
	malloced_list = (t_dict *)malloc(sizeof(t_dict) * linenumber);
	if (make_struct(malloced_list, sizes, filename) < 0)
		write_dict_error();
	else if (after_work(malloced_list, list, linenumber) <= 0)
		write_dict_error();
	else
		process_str(str, list);
	free_all(malloced_list, linenumber, list);
	free(sizes);
}

int	count_lastnum(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (count > 0 || *str != '0')
			count++;
		str++;
	}
	return (count);
}

int	move_str_amount(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] != '0')
			return (count);
		count++;
	}
	return (count);
}

void	process_str(char *str, t_dict *list)
{
	int	size;
	int	cur_size;

	size = ft_strlen(str);
	while (size > 0)
	{
		cur_size = (size - 1) % 4 + 1;
		print_cheon(str, list, cur_size, (size - 1) / 4 * 4 + 1);
		print_man((size - 1) / 4 * 4 + 1, list);
		size -= cur_size;
		str += cur_size;
		size -= move_str_amount(str);
		str += move_str_amount(str);
		if (size >= 1)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
