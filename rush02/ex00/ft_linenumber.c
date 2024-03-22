/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linenumber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:14:59 by ska               #+#    #+#             */
/*   Updated: 2023/09/10 13:54:22 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	get_linenumber(char *filename)
{
	t_file_read	fr;
	int			count;
	int			flag;

	flag = 0;
	count = 0;
	if (first_read(&fr, filename) == -1)
		return (-1);
	while (fr.r > 0)
	{
		if (fr.buff == '\n')
		{
			count++;
			flag = 1;
		}
		else
			flag = 0;
		fr.r = read(fr.fd, &fr.buff, 1);
	}
	close(fr.fd);
	if (flag == 0)
		return (-1);
	return (count);
}
