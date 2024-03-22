/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:51:45 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/13 11:56:50 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
int		ft_strcmp(char *s1, char *s2);
void	init_save(char *save);
void	display(char *file_name, char *program_name);
void	print_error(char *file_name, char *program_name, char *error);
void	read_stdin(void);

#endif
