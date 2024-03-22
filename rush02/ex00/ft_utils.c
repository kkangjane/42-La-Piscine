/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:59:07 by ska               #+#    #+#             */
/*   Updated: 2023/09/09 20:59:36 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	first_read(t_file_read *fr, char *filename)
{
	fr->fd = open(filename, O_RDONLY);
	if (fr->fd < 0)
		return (-1);
	fr->r = read(fr->fd, &fr->buff, 1);
	if (fr->r < 0)
	{
		close(fr->fd);
		return (-1);
	}
	return (0);
}
