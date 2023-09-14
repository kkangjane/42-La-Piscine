# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 12:17:14 by jae-kang          #+#    #+#              #
#    Updated: 2023/09/07 12:17:16 by jae-kang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c *.c -Wall -Werror -Wextra
ar -cr libft.a  ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
