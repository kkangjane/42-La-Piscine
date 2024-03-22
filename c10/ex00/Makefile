# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 20:08:43 by jae-kang          #+#    #+#              #
#    Updated: 2023/09/13 11:36:33 by jae-kang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = *.c
TARGET = ft_display_file

all : $(TARGET)

$(TARGET) : $(SRCS)
	gcc -o $(TARGET) $(SRCS)

clean :
	rm -f *.o

fclean : clean
	rm -f ft_display_file

re : fclean all
