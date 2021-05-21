/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:38:26 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/14 08:38:49 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int			main(int argc, char **argv)
{
	char	*file_name;
	t_data	*data;

	if (argc != 2)
		exit(!!ft_printf(ERR_IN));
	data = (t_data*)ft_memalloc(sizeof(t_data));
	get_data(data);
	data->fd_r = open(argv[argc - 1], O_RDONLY);
	if (data->fd_r < 3 || read(data->fd_r, NULL, 0) < 0)
		exit(!!ft_printf(ERR_NO_READ, argv[argc - 1]));
	file_name = set_output_name(argv[argc - 1]);
	basic_transformations(data);
	data->fd_w = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (data->fd_w < 3)
		exit(!!ft_printf(ERR_NOT_CR, file_name));
	write_data(data);
	ft_printf(GOOD_OUT, file_name);
	free_str_arr(&file_name, NULL, 0);
	free_data(data);
	return (0);
}
