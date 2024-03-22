#ifndef FT_H
# define FT_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>
#include <stdio.h>

/* main.c */


/* ft_display_tail.c */
void	display_tail(char *argv[], int file_index, int only, int size);
void	raise_index(int *index, int size);
void    write_stdin_tail(int size);
void	display_all(char *file_name);

/* ft_functions.c */
int     ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		is_small(char *file_name, int size);

/* ft_print.c */
void    ft_putstr(char *str);
void    print_error(char *file_name, char *program_name, char *error);
void    write_filename(char *file_name);
void    print_error_illegal_offset(char *program_name, char *illegal_offset);
void	print_buf(char *buf, int index, int size);

#endif
