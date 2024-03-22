/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:16:10 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/13 11:37:33 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display(char *file_name)
{
	int		fp;
	char	c;

	fp = open(file_name, O_RDONLY);
	if (fp < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	while (1)
	{
		if (read(fp, &c, 1) > 0)
			write(1, &c, 1);
		else
			break ;
	}
	close(fp);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		ft_display(argv[1]);
	return (0);
}
