/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:25:17 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/09 21:26:52 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_size(int count, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (i < count)
	{
		j = 0;
		while (strs[i][j])
			j++;
		len += j;
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	len += i * (count - 1);
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		len;

	if (size == 0)
	{
		result = (char *) malloc(1);
		result[0] = 0;
		return (result);
	}
	len = find_size(size, strs, sep);
	result = (char *)malloc(len + 1);
	if (result == 0)
		return (0);
	*result = '\0';
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i != size - 1)
			result = ft_strcat(result, sep);
		i++;
	}
	return (result);
}
/*
#include <unistd.h>
int	main(void)
{
	char	*strs[5] = {"Hello", "my", "name", "is", "jae-kang"};
	char	*space = " ";
	char	*result;

	result = ft_strjoin(5, strs, space);
	int	i = 0;
	while (result[i])
		write(1, &result[i++], 1);
	return (0);
}*/
