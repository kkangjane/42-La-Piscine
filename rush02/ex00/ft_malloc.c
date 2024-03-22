/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:56:58 by ska               #+#    #+#             */
/*   Updated: 2023/09/10 18:11:00 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*malloc_keysize(char *key, int minus_flag)
{
	int		len;
	char	*dest;

	len = 0;
	while ('0' <= key[len] && key[len] <= '9')
		len++;
	if (minus_flag && len > 0)
		len++;
	if (len == 0)
		len = 1;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	return (dest);
}

void	set_key(char *dest, char *key, int minus_flag)
{
	int	len;

	len = 0;
	while ('0' <= key[len] && key[len] <= '9')
	{
		if (len == 0 && minus_flag)
			*dest++ = '-';
		dest[len] = key[len];
		len++;
	}
	if (len == 0)
		dest[len++] = '0';
	dest[len] = 0;
}

char	*copy_key(char *key)
{
	char	*dest;
	int		minus_flag;

	minus_flag = 0;
	while (*key == ' ')
		key++;
	if (*key == '-')
	{
		minus_flag = 1;
		key++;
	}
	else if (*key == '+')
		key++;
	while (*key == '0')
		key++;
	dest = malloc_keysize(key, minus_flag);
	set_key(dest, key, minus_flag);
	return (dest);
}

char	*copy_value(char *src)
{
	char	*ret;
	int		flag;
	int		idx;

	if (calculate_valuesize(src) <= 1)
		return (0);
	ret = (char *)malloc(sizeof(char) * calculate_valuesize(src));
	flag = 0;
	idx = 0;
	while (*src == ' ')
		src++;
	while (*src)
	{
		if (*src == ' ' && src++)
			flag = 1;
		else
		{
			if (flag)
				ret[idx++] = ' ';
			ret[idx++] = *src++;
			flag = 0;
		}
	}
	ret[idx] = 0;
	return (ret);
}

t_new_keys	*get_new_keys(char *dest)
{
	t_new_keys	*ret;

	ret = (t_new_keys *)malloc(sizeof(t_new_keys));
	ret->key = dest;
	ret->key_len = ft_strlen(dest);
	ret->next = 0;
	return (ret);
}
