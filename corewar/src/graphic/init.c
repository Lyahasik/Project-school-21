/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 02:15:54 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/06 17:11:58 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "corewar_struct.h"

/*
** Инициализация структур sdl. Отключение отлова мыши.
** @param sdl указатель на структуру для sdl.
** @return 0 - error, 1 - ok.
*/

static int	init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0
		|| !(sdl->window = SDL_CreateWindow("Corewar",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE_W, SIZE_H, 0))
		|| !(sdl->renderer = SDL_CreateRenderer(sdl->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
	{
		return (ft_out_message(ERR_SDL_INIT, 0));
	}
	SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
	return (1);
}

/*
** Инициализация структуры для меню.
** @param menu указатель на структуру для меню.
** @return 0 - error, 1 - ok.
*/

static int	init_menu(t_menu *menu, SDL_Renderer *renderer)
{
	if (!init_operations(menu, renderer)
		|| !init_text(menu, renderer)
		|| !init_figures(menu, renderer))
		return (0);
	menu->background.x = SIZE_W - MENU_W - SHIFT;
	menu->background.y = SHIFT;
	menu->background.w = MENU_W;
	menu->background.h = SIZE_H - SHIFT * 2;
	return (1);
}

/*
** Расчет размера ячеек.
** @param field указатель на структуру поля.
** @return 0 - error, 1 - ok.
*/

static int	calculation_size_cell(t_field *field)
{
	int	number_rows;
	int	size_side;

	number_rows = ft_sqrt_int(MEM_SIZE);
	if (number_rows * number_rows != MEM_SIZE)
		number_rows++;
	size_side = (field->border.w - 1) / number_rows;
	if (size_side < 6)
		return (ft_out_message(ERR_CELL_NUM, 0));
	field->cell_size.x = size_side - 1;
	field->cell_size.y = size_side - 1;
	field->row_length = (field->border.w - 1) / size_side;
	return (1);
}

/*
** Инициализация структуры для поля.
** @param field указатель на структуру поля.
** @return 0 - error, 1 - ok.
*/

static int	init_field(t_field *field)
{
	int	number_rows;
	int	module;

	field->border.x = SHIFT + BOLD_BORDER;
	field->border.y = SHIFT + BOLD_BORDER;
	field->border.w = SIZE_W - MENU_W - SHIFT * 3 - BOLD_BORDER * 2;
	field->border.h = SIZE_H - SHIFT * 2 - BOLD_BORDER * 2;
	if (!calculation_size_cell(field))
		return (0);
	number_rows = ft_sqrt_int(MEM_SIZE);
	module = (number_rows * number_rows != MEM_SIZE) ? 1 : 0;
	field->cell_shift_x = (field->border.w - 1 - (field->cell_size.x + 1)
		* field->row_length) / 2;
	field->cell_shift_y = (field->border.h - 1 - (MEM_SIZE / field->row_length
		+ module) * (field->cell_size.y + 1)) / 2;
	if (!(field->cells = (t_cell*)malloc(sizeof(t_cell) * MEM_SIZE)))
		return (ft_out_message(ERR_MEM, 0));
	return (1);
}

/*
** Инициализация структуры для графики.
** @return 0 - error.
*/

t_graphic	*init_graphic(t_graphic *graphic)
{
	if (!(graphic->sdl = allocation_sdl())
		|| !(graphic->menu = allocation_menu())
		|| !(graphic->field = allocation_field()))
	{
		return (NULL);
	}
	if (!init_sdl(graphic->sdl) || !init_field(graphic->field)
		|| !init_menu(graphic->menu, graphic->sdl->renderer))
	{
		return (NULL);
	}
	graphic->delay = DELAY_THREE;
	graphic->stop = 1;
	return (graphic);
}
