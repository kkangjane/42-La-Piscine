/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:37:52 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/12 12:25:19 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*num_check_clean(char *str)
{
	char	*num;
	int		i;

	if (str[0] == '0')
		return (write_error());
	num = (char *)malloc(sizeof(char) * 40);
	i = 0;
	while (i < 39 && str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			free(num);
			return (write_error());
		}
		num[i] = str[i];
		i++;
	}
	if (str[i])
	{
		free(num);
		write_dict_error();
		return (0);
	}
	num[i] = 0;
	return (num);
}

void	process_argc2(char *num_str)
{
	char	*num_arg;

	if (num_str[0] == 0)
	{
		write_error();
		return ;
	}
	if (num_str[0] == '0' && num_str[1] == 0)
	{
		num_arg = (char *)malloc(sizeof(char) * 2);
		num_arg[0] = '0';
		num_arg[1] = 0;
	}
	else
		num_arg = num_check_clean(num_str);
	if (num_arg == 0)
		return ;
	process(num_arg, "numbers.dict");
	free(num_arg);
}

void	process_argc3(char *file_name, char *num_str)
{
	char	*num_arg;

	if (num_str[0] == 0)
	{
		write_error();
		return ;
	}
	if (num_str[0] == '0' && num_str[1] == 0)
	{
		num_arg = malloc(2);
		num_arg[0] = '0';
		num_arg[1] = 0;
	}
	else
		num_arg = num_check_clean(num_str);
	if (num_arg == 0)
		return ;
	process(num_arg, file_name);
	free(num_arg);
}

int	process_argc1(int index, char c)
{
	char	num_arg[40];
	int		r;

	r = 0;
	r = read(0, &c, 1);
	while (r && index < 39)
	{
		if (c == '\n')
			break ;
		num_arg[index++] = c;
		r = read(0, &c, 1);
	}
	if (index == 39 && r && c != '\n')
	{
		while (r)
		{
			if (c == '\n')
				break ;
			r = read(0, &c, 1);
		}
		return (0);
	}
	num_arg[index] = 0;
	process_argc2(num_arg);
	return (1);
}

int	main(int argc, char *argv[])
{
	int		index;
	char	c;

	index = 0;
	c = 0;
	if (argc == 1)
	{
		if (process_argc1(index, c) == 0)
			write_dict_error();
	}
	else if (argc == 2)
		process_argc2(argv[1]);
	else if (argc == 3)
		process_argc3(argv[1], argv[2]);
	else
		write_error();
	return (0);
}
