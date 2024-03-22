/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:02:10 by ska               #+#    #+#             */
/*   Updated: 2023/09/12 00:30:21 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	init_list(t_dict list[])
{
	int	i;

	i = 0;
	while (i < 41)
	{
		list[i].key = 0;
		list[i].key_len = 0;
		list[i].value = 0;
		i++;
	}
}

void	process(char *str, char *filename)
{
	t_dict			list[41];
	t_dict			*malloced_list;
	t_char_sizes	*sizes;
	int				linenumber;
	linenumber = get_linenumber(filename); //파일을 열어서 개행을 얻는 만큼 줄 수를 센다.
	if (linenumber < 0)
		return (write_dict_error());
	sizes = (t_char_sizes *)malloc(sizeof(t_char_sizes) * linenumber); //줄 수 만큼 sizes 구조체 배열을 동적 할당한다.
	if (get_char_sizes(sizes, filename) < 0) //get_char_sizes를 통해서 sizes 구조체를 업데이트 해준다.
	{
		free(sizes);
		return (write_dict_error());
	}
	//이제 줄 수만큼 malloced_list를 동적 할당 해준다.
	malloced_list = (t_dict *)malloc(sizeof(t_dict) * linenumber);
	if (make_struct(malloced_list, sizes, filename) < 0)
		write_dict_error();
	//after_work, 즉 후처리를 한 후 결과가 나쁘면 dict error를 출력한다.
	else if (after_work(malloced_list, list, linenumber) <= 0)
		write_dict_error();
	//그 다음은 process_str을 실행해서 이제 사전을 조합하면 된다.
	else
		process_str(str, list);
	//다 끝났으면 프리 올~~욜~~
	free_all(malloced_list, linenumber, list);
	free(sizes);
}

int	count_lastnum(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (count > 0 || *str != '0')
			count++;
		str++;
	}
	return (count);
}

int	move_str_amount(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] != '0')
			return (count);
		count++;
	}
	return (count);
}

void	process_str(char *str, t_dict *list)
{
	int	size;
	int	cur_size;

	size = ft_strlen(str);
	while (size > 0)
	{
		cur_size = (size - 1) % 3 + 1;
		print_hundreds(str, list, cur_size);
		print_thousand((size - 1) / 3 * 3 + 1, list);
		size -= cur_size;
		str += cur_size;
		size -= move_str_amount(str);
		str += move_str_amount(str);
		if (size >= 3)
			write(1, ", ", 2);
		else if (size >= 1)
			write(1, " and ", 5);
	}
	write(1, "\n", 1);
}
