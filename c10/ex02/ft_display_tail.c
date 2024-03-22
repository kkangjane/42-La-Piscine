/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:47:05 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/13 17:53:43 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_tail(char *argv[], int file_index, int only, int size)
{
	int		fp;
	int		count;
	int		index;
	char	c;
	char	*buf;
	
	if (only == 0 && read(fp, &c, 1) < 0)
		write_filename(argv[file_index]);
	fp = open(argv[file_index], O_RDONLY);
	if (fp < 0)
	{
		print_error(argv[0], argv[file_index], strerror(errno));
		return ;
	}
	if (is_small(argv[file_index], size))
	{
		close(fp);
		return ;
	}
	buf = (char *) malloc(size);
	index = 0;
	buf[index] = c;
	raise_index(&index, size);
	while (read(fp, &c, 1) > 0)
	{
		buf[index] = c;
		raise_index(&index, size);
	}
	print_buf(buf, index, size);
	close(fp);
}

void	raise_index(int *i, int size)
{
	if (*i + 1 < size)
		*i = *i + 1;
	else
		*i = 0;
}

void	write_stdin_tail(int size)
{
	
}

void	display_all(char *file_name)
{
	int		fp;
	char	c;

	fp = open(file_name, O_RDONLY);
	while (1)
	{
		if (read(fp, &c, 1) > 0)
			write(1, &c, 1);
		else
			break ;
	}
	close(fp);
}
