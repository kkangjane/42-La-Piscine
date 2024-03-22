/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_sizes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:59:33 by ska               #+#    #+#             */
/*   Updated: 2023/09/12 00:24:33 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	handle_buff_enter(int *flag, int *count, t_char_sizes *s)
{
	if (*flag == 0)
	{
		if (*count > 0)
			return (-1);
		s->key_size = 0;
		s->value_size = 0;
	}
	else
	{
		if (*count == 0)
			return (-1);
		s->value_size = *count;
		*flag = 0;
		*count = 0;
	}
	return (0);
}

int	handle_buff_colon(int *flag, int *count, t_char_sizes *s)
{
	if (*flag != 0)
		return (-1);
	s->key_size = *count;
	*count = 0;
	*flag = 1;
	return (0);
}

int	buff_valid(t_file_read *fr, int *flag, int *count, t_char_sizes *s)
{
	//만약 개행이면 handle_buff_enter을 통해서 
	if (fr->buff == '\n')
	{
		if (handle_buff_enter(flag, count, s) == -1)
			return (-1);
	}
	else if (fr->buff == ':')
	{
		if (handle_buff_colon(flag, count, s) == -1)
			return (-1);
	}
	else
		(*count)++;
	return (0);
}

int	get_char_sizes(t_char_sizes *sizes, char *filename)
{
	t_file_read	fr;
	int			flag;
	int			idx;
	int			count;

	if (first_read(&fr, filename) == -1)
		return (-1);
	flag = 0;
	idx = 0;
	count = 0;
	//개행을 받을 때마다 idx를 업데이트한다. buff_valid(fr, flag, count, sizes)를 통해 그 줄이 괜찮은 줄인지 확인한다.
	while (fr.r > 0)
	{
		if (buff_valid(&fr, &flag, &count, &sizes[idx]) == -1)
		{
			close(fr.fd);
			return (-1);
		}
		if (fr.buff == '\n')
			idx++;
		fr.r = read(fr.fd, &fr.buff, 1);
	}
	close(fr.fd);
	return (0);
}
