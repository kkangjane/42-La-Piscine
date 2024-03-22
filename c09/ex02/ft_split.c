/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:17:02 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/08 18:26:39 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count(char *str, char *charset)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset) == 1)
			flag = 0;
		else
		{
			if (flag == 0)
			{
				flag = 1;
				count++;
			}
		}
		i++;
	}
	return (count);
}

char	*ft_strdup(char *str, char *charset)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset) == 1)
			break ;
		i++;
	}
	result = (char *)malloc(i + 1);
	i = 0;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset) == 1)
			break ;
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		flag;
	int		index;

	i = 0;
	flag = 0;
	index = 0;
	result = (char **) malloc(sizeof(char *) * (ft_count(str, charset) + 1));
	while (str[i])
	{
		if (ft_is_charset(str[i], charset) == 1)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			result[index++] = ft_strdup(&str[i], charset);
		}
		i++;
	}
	result[index] = 0;
	return (result);
}
