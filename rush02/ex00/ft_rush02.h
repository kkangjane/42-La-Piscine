/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:34:47 by ska               #+#    #+#             */
/*   Updated: 2023/09/12 01:45:32 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H
# define FT_RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
	int		key_len;
}	t_dict;

typedef struct s_new_keys
{
	char				*key;
	int					key_len;
	struct s_new_keys	*next;
}	t_new_keys;

typedef struct s_file_read
{
	char	buff;
	int		fd;
	int		r;
}	t_file_read;

typedef struct s_char_sizes
{
	int	key_size;
	int	value_size;
}	t_char_sizes;

/* char_sizes.c */
int			handle_buff_enter(int *flag, int *count, t_char_sizes *s);
int			handle_buff_colon(int *flag, int *count, t_char_sizes *s);
int			buff_valid(t_file_read *fr, int *flag, int *count, t_char_sizes *s);
int			get_char_sizes(t_char_sizes *sizes, char *filename);

/* check.c */
//nb가 len만큼 10000느낌으로 되어있는지 체크
int			one_all_zero(char *nb, int len);
//list[]에 key가 있는지
int			check_unique(char *key, t_dict list[], int list_num);
//key가 초기 list에 있는지...? 그니까 사전에 그 자체의 key가 있는지.... 바로 가져올 수 있는지...
int			is_in_initial(char *key);

/* error.c */
char		*write_error(void);
void		write_dict_error(void);

/* ft_afterwork.c */
//str의 길이를 잰다. 여기서 str은 value나 key의 초기 모습이겠지? 공백같은거를 제거하고 넣는거다.
int			calculate_valuesize(char *str);
//이제 nkeys가 다 중복인지 확인을 해야 하나...?
int			is_additional_duplicate(t_new_keys **nkeys, char *dest);
int			examine(t_dict *mele, t_new_keys **new_keys, char **ret_dest);
int			insert_dest(char *dest, t_dict list[], int lis_len, char *value);
int			after_work(t_dict *mlist, t_dict list[], int malloced_size);

/* ft_free.c */
void		free_new_keys(t_new_keys *new_keys);
void		free_all(t_dict *malloced_list, int malloc_size, t_dict list[]);

/* ft_linenumber.c */
int			get_linenumber(char *filename);

/* ft_malloc.c */
char		*malloc_keysize(char *key, int minus_flag);
void		set_key(char *dest, char *key, int minus_flag);
char		*copy_key(char *key);
char		*copy_value(char *src);
t_new_keys	*get_new_keys(char *dest);

/* ft_utils.c */
int			ft_strlen(char *str);
int			first_read(t_file_read *fr, char *filename);

/* main.c */
char		*num_check_clean(char *str);
void		process_argc2(char *num_str);
void		process_argc3(char *file_name, char *num_str);

/* make_struct.c */
char		*read_key(t_file_read *fr, int size);
int			make_struct(t_dict list[], t_char_sizes *sizes, char *filename);

/*print_num.c*/
void		print_num(char *list);
int			check_3(char *str, t_dict *list, int size);
int			check_2(char *str, t_dict *list, int size);
int			check_1(char *str, t_dict *list, int size);
void		print_hundreds(char *str, t_dict *list, int size);

/*print_thousand.c*/
int			check_thousands(int size, char *key);
void		print_thousand(int size, t_dict *list);

/* process_dict.c */
void		init_list(t_dict list[]);
void		process(char *str, char *filename);
int			count_lastnum(char *str);
int			move_str_amount(char *str);
void		process_str(char *str, t_dict *list);
#endif
