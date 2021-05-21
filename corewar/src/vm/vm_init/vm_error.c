/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:14:52 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/13 21:00:53 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

char		g_error[100][100] =
{
	"ERROR: no error",
	"USAGE: ./corewar [[-dump N] [[-n N] file.cor] [[-n N] file.cor] ...]",
	"ERROR: number of players exceeds MAX_PLAYERS",
	"ERROR: not enough memory to allocate",
	"ERROR: wrong file extension",
	"ERROR: cannot open file",
	"ERROR: cannot close file",
	"ERROR: file is empty",
	"ERROR: wrong binary encoding",
	"ERROR: execution code size doesn't match header",
	"ERROR: execution code exceeds CHAMP_MAX_SIZE",
	"ERROR: invalid flag",
	"FAIR PLAY ERROR: one player is unarmed",
	"ERROR: no players - no MEAL'n'REAL"
};

void	vm_error(int error_code)
{
	ft_printf("%s\n", g_error[error_code]);
	exit(error_code);
}
