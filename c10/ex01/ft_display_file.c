/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:16:10 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/13 11:43:20 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display(char *file_name, char *program_name)
{
	int		fp;
	char	c;

	fp = open(file_name, O_RDONLY);
	if (fp < 0 || read(fp, &c, 1) < 0)
	{
		print_error(file_name, program_name, strerror(errno));
		if (fp > 0)
			close(fp);
		return ;
	}
	else
		write(1, &c, 1);
	while (read(fp, &c, 1) > 0)
		write(1, &c, 1);
	close(fp);
}

void	print_error(char *file_name, char *program_name, char *error)
{
	ft_putstr_error(basename(program_name));
	write(2, ": ", 2);
	ft_putstr_error(file_name);
	write(2, ": ", 2);
	ft_putstr_error(error);
	write(2, "\n", 1);
}
