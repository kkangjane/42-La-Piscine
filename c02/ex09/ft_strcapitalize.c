/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:31:13 by jae-kang          #+#    #+#             */
/*   Updated: 2023/08/25 18:19:52 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_what_is(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= '0' && c <= '9')
		return (3);
	else
		return (0);
}

char	*ft_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_what_is(str[i]) == 2)
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	str = ft_lower(str);
	if (ft_what_is(str[0]) == 1)
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_what_is(str[i - 1]) == 0 && ft_what_is(str[i]) == 1)
			str[i] -= 32;
		i++;
	}
	return (str);
}
