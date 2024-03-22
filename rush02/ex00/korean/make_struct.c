/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:48:58 by ska               #+#    #+#             */
/*   Updated: 2023/09/09 21:01:42 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*read_key(t_file_read *fr, int size)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (fr->r > 0 && i < size - 1)
	{
		ret[i] = fr->buff;
		fr->r = read(fr->fd, &fr->buff, 1);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	make_struct(t_dict list[], t_char_sizes *sizes, char *filename)
{
	int			idx;
	int			i;
	t_file_read	fr;

	if (first_read(&fr, filename) == -1)
		return (-1);
	idx = 0;
	while (fr.r > 0)
	{
		i = 0;
		list[idx].key = read_key(&fr, sizes[idx].key_size + 1);
		if (fr.buff == ':')
			fr.r = read(fr.fd, &fr.buff, 1);
		list[idx].value = read_key(&fr, sizes[idx].value_size + 1);
		idx++;
		fr.r = read(fr.fd, &fr.buff, 1);
	}
	close(fr.fd);
	return (0);
}
