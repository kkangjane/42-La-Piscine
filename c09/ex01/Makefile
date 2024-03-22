# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 11:12:46 by jae-kang          #+#    #+#              #
#    Updated: 2023/09/09 16:12:13 by jae-kang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJECT = ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o
TARGET = libft.a

all : $(TARGET)

%.o : %.c
	gcc -c $< -o $@ -Wall -Werror -Wextra -Iincludes

$(TARGET) : $(OBJECT)
	ar -cr $(TARGET) $(OBJECT)

clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(TARGET)

re : fclean all
