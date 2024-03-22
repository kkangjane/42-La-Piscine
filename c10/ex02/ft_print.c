#include "ft.h"

void	ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

void	print_error(char *program_name, char *file_name, char *error)
{
	ft_putstr(basename(program_name));
	write(2, ": ", 2);
	ft_putstr(file_name);
	write(2, ": ", 2);
	ft_putstr(error);
	write(2, "\n", 1);
}

void	write_filename(char *file_name)
{
    write(1, "\n==> ", 5);
    ft_putstr(file_name);
    write(1, " <==\n", 5);
}

void	print_error_illegal_offset(char *program_name, char *illegal_offset)
{
    ft_putstr(basename(program_name));
    write(2, ": illegal offset -- ", 20);
    ft_putstr(illegal_offset);
}

void	print_buf(char *buf, int index, int size)
{
	int	final_index;

	if (index == 0)
		final_index = size - 1;
	else
		final_index = index - 1;
	while (1)
	{
		write(1, &buf[index], 1);
        if (final_index == index)
			break;
		raise_index(&index, size);	
	}
}
