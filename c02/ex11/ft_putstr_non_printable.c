/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:27:05 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/07 17:45:59 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_printable(unsigned char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char	*str)
{
	int				i;
	char			*c;
	unsigned char	*copy;

	copy = (unsigned char *) str;
	c = "0123456789abcdef";
	i = 0;
	while (copy[i])
	{
		if (ft_is_printable(copy[i]))
			write(1, &copy[i], 1);
		else
		{
			write(1, "\\", 1);
			write(1, &c[copy[i] / 16], 1);
			write(1, &c[copy[i] % 16], 1);
		}
		i++;
	}
}
