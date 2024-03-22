#include "ft.h"

int main(int argc, char *argv[])
{
	int		size;
	int		index;

	if (argc < 3)
		return (0);
	if (argc == 3)
		write_stdin_tail(size);
	size = ft_atoi(argv[2]);
	if (size == -1)
	{
		print_error_illegal_offset(argv[0], argv[2]);
		return (0);
	}
	index = 3;
	if (argc == 4)
	{
		display_tail(argv, index, 1, size);
		return (0);
	}
	while (index < argc)
	{
		display_tail(argv, index, 0, size);
		index++;
	}
	return (0);
}
