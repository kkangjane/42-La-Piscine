TARGET = do-op
SRC = ft_doop.c
MAKEFLAGS += --silent

all : $(SRC)
	cc -o $(TARGET) $(SRC) -Wall -Wextra -Werror

clean : $(OBJECT)
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(TARGET)

re : fclean all
