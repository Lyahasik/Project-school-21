/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:27:47 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/13 21:01:08 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

static void	read_file(t_file *file, int fd)
{
	int		ret;
	char	buff[B_S + 1];
	char	*tmp;
	int		i;

	tmp = NULL;
	while ((ret = read(fd, buff, B_S)))
	{
		tmp = ft_memalloc(file->size + ret);
		i = -1;
		while (++i < (int)file->size)
			tmp[i] = file->raw[i];
		i = -1;
		while (++i < ret)
			tmp[i + file->size] = buff[i];
		free(file->raw);
		file->raw = tmp;
		file->size += ret;
	}
}

static void	valid_champ(t_vm *vm, int i)
{
	t_file	file;
	void	*curr;

	ft_bzero(&file, sizeof(t_file));
	read_file(&file, PLAYER[i].fd);
	if (!file.size)
		vm_error(7);
	if (reverse_bytes(*(unsigned*)(curr = file.raw)) ^ COREWAR_EXEC_MAGIC)
		vm_error(8);
	curr += 4;
	ft_memcpy(PLAYER[i].name, curr, (size_t)PROG_NAME_LENGTH + 1);
	curr += PROG_NAME_LENGTH + 1 + 4 - (PROG_NAME_LENGTH + 1) % 4;
	PLAYER[i].exec_size = reverse_bytes(*(unsigned*)curr);
	curr += 4;
	ft_memcpy(PLAYER[i].comment, curr, (size_t)COMMENT_LENGTH + 1);
	curr += COMMENT_LENGTH + 1 + 4 - (COMMENT_LENGTH + 1) % 4;
	file.size -= sizeof(t_header);
	valid_exec_size(vm, file, i);
	ft_memcpy(PLAYER[i].exec_code, curr, file.size);
	free(file.raw);
}

static void	valid_files(t_vm *vm)
{
	int i;

	i = -1;
	while (++i < N_PLAYERS)
	{
		PLAYER[i].fd = open(PLAYER[i].file, O_RDONLY);
		if (PLAYER[i].fd < 0)
			vm_error(5);
		valid_champ(vm, i);
		if (close(PLAYER[i].fd) < 0)
			vm_error(6);
	}
}

static void	valid_args(t_vm *vm, char **input)
{
	int			i;
	int			count;

	i = -1;
	count = 0;
	while ((*input) && *(++input))
	{
		if (**input == '-')
			input = valid_flags(vm, input, &i, &count);
		else if (ft_strstr(*input, ".cor"))
			input = valid_filename(vm, input, &i, &count);
		else
			vm_error(4);
	}
	if (!(N_PLAYERS = i + 1))
		vm_error(13);
}

void		vm_valid(t_vm *vm, char **input)
{
	valid_args(vm, input);
	valid_files(vm);
}
