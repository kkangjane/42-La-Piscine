/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:26:44 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/13 11:55:56 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		read_stdin();
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-") == 0)
			read_stdin();
		else
			display(argv[i], argv[0]);
		i++;
	}
	return (0);
}
