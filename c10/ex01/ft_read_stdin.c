/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:44:05 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/13 11:45:43 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	read_stdin(void)
{
	int		i;
	char	save[300721];
	char	c;

	i = 0;
	init_save(save);
	while (read(0, &c, 1) > 0)
	{
		save[i++] = c;
		if (c == '\n')
		{
			ft_putstr(save);
			i = 0;
			init_save(save);
		}
	}
	ft_putstr(save);
}
