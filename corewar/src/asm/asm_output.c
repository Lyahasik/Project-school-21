/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:43:18 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/10 19:05:27 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static void	write_reverse(int fd, unsigned char *str, unsigned full_size)
{
	while (full_size > 0)
	{
		full_size--;
		write(fd, &str[full_size], 1);
	}
}

static void	write_name_comment(int fd, char *str, unsigned full_size)
{
	int		len;
	char	*zero;

	len = (int)ft_strlen(str);
	zero = (char*)ft_memalloc(sizeof(char) * (full_size - len + 1));
	write(fd, str, len);
	write(fd, zero, (full_size - len));
	free_str_arr(&zero, NULL, 0);
}

static void	select_type(int fd, t_operation *op, int arg_nr)
{
	unsigned char	c;
	unsigned short	s;
	unsigned int	i;

	if (op->arg_type[arg_nr] == 1)
	{
		c = (unsigned char)op->arg[arg_nr];
		write_reverse(fd, (unsigned char*)(&c), sizeof(c));
	}
	else if (op->arg_type[arg_nr] == 2
		&& T_DIR_SIZE[op->instruction_id] == 4)
	{
		i = (unsigned int)op->arg[arg_nr];
		write_reverse(fd, (unsigned char*)(&i), sizeof(i));
	}
	else
	{
		s = (unsigned short)op->arg[arg_nr];
		write_reverse(fd, (unsigned char*)(&s), sizeof(s));
	}
}

static void	write_operation(int fd, t_operation *op)
{
	unsigned char	a;
	int				i;

	a = (unsigned char)op->instruction_id;
	write_reverse(fd, (unsigned char*)(&a), sizeof(a));
	if (op->octet != 0)
	{
		a = (unsigned char)op->octet;
		write_reverse(fd, (unsigned char*)(&a), sizeof(a));
	}
	i = 0;
	while (i < ARGS_QTY[op->instruction_id])
	{
		select_type(fd, op, i);
		i++;
	}
}

void		write_data(t_data *data)
{
	int			magic;
	int			zero;
	t_operation	*op;

	magic = COREWAR_EXEC_MAGIC;
	zero = 0;
	write_reverse(data->fd_w, (unsigned char*)(&magic), sizeof(int));
	write_name_comment(data->fd_w, data->name, PROG_NAME_LENGTH);
	write(data->fd_w, (unsigned char*)(&zero), sizeof(int));
	write_reverse(data->fd_w, (unsigned char*)(&data->full_size), sizeof(int));
	write_name_comment(data->fd_w, data->comment, COMMENT_LENGTH);
	write(data->fd_w, (unsigned char*)(&zero), sizeof(int));
	op = data->op;
	while (op != NULL)
	{
		write_operation(data->fd_w, op);
		op = op->next;
	}
}
