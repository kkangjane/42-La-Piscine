/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:13:02 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/06 10:13:02 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			find_from_base(char *base, char c);
int			is_base(char *base);
long long	ft_convert_btoi(char *nbr, char *base, int i, int flag);
char		*ft_convert_itob(long long nbr, char *base, int base_size);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	result;
	int			flag;
	int			i;
	char		*c;

	if (is_base(base_from) == 0 || is_base(base_to) == 0)
		return (0);
	i = 0;
	flag = 1;
	while ((nbr[i] > 8 && nbr[i] < 14) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			flag *= -1;
		i++;
	}
	result = ft_convert_btoi(nbr, base_from, i, flag);
	i = 0;
	while (base_to[i])
		i++;
	c = ft_convert_itob(result, base_to, i);
	return (c);
}

long long	ft_convert_btoi(char *nbr, char *base, int i, int flag)
{
	long long	result;
	long long	base_size;

	result = 0;
	base_size = 0;
	while (base[base_size])
		base_size++;
	while (find_from_base(base, nbr[i]) != -1)
	{
		result = result * base_size + (long long) find_from_base(base, nbr[i]);
		i++;
	}
	if (flag == -1)
		result *= -1;
	return (result);
}

int	is_base(char *base)
{
	int	i;
	int	board[128];

	i = 0;
	while (i < 128)
		board[i++] = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (board[(int) base[i]] == 1)
			return (0);
		board[(int) base[i++]] = 1;
	}
	return (1);
}

int	find_from_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_convert_itob(long long nbr, char *base, int base_size)
{
	int		index[32];
	char	*result;
	int		i;
	int		j;

	result = (char *) malloc(33);
	i = 0;
	j = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		result[j++] = '-';
	}
	if (nbr == 0)
		result[j++] = base[0];
	while (nbr > 0)
	{
		index[i++] = nbr % base_size;
		nbr /= base_size;
	}
	while (--i >= 0)
		result[j++] = base[index[i]];
	result[j] = '\0';
	return (result);
}
/*
#include <unistd.h>
int     main()
{
		char	*base_from = "0123456789";
		char	*base_to = "0123456789abcdef";
		char	*nbr = "     \t +++----214748347";
        char    *result;
		int		i = 0;

        result = ft_convert_base(nbr, base_from, base_to);
		while (result[i])
			write(1, &result[i++], 1);
		return (0);
}
*/
