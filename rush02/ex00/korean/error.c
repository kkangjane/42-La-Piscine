/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:55:20 by ska               #+#    #+#             */
/*   Updated: 2023/09/10 17:26:15 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*write_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void	write_dict_error(void)
{
	write(1, "Dict Error\n", 11);
}