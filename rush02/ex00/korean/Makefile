SRCS = char_sizes.c \
	   check.c \
	   error.c \
	   ft_afterwork.c \
	   ft_free.c \
	   ft_linenumber.c \
	   ft_malloc.c \
	   ft_utils.c \
	   main.c \
	   make_struct.c \
	   print_cheon.c \
	   print_man.c \
	   process_dict.c
OBJS = $(SRCS:.c=.o)
TARGET = rush-02
CFLAGS = -Wall -Werror -Wextra

all: $(TARGET)

$(TARGET): $(SRCS)
	cc $(CFLAGS) -o $(TARGET) $(SRCS)

fclean: clean
	rm -f $(TARGET)

clean: 
	rm -f $(OBJS)

re:
	make fclean
	make all
