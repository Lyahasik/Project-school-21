/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:53:32 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/09 17:22:53 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "../../header/corewar.h"

/*
** Вывод прямоугольника без заливки.
** @param sdl структура отрисовки.
** @param border структура прямоугольника.
** @return 0 - error, 1 - ok.
*/

int	put_border(t_sdl *sdl, SDL_Rect border, int bold, int color)
{
	while (bold-- > 0)
	{
		border.x--;
		border.y--;
		border.h += 2;
		border.w += 2;
		if (set_color(sdl, color) < 0
			|| SDL_RenderDrawRect(sdl->renderer, &border) < 0)
		{
			return (ft_out_message((char*)SDL_GetError(), 0));
		}
	}
	return (1);
}

/*
** Вывод ячейки.
** @param sdl структура отрисовки.
** @param field структура поля.
** @return 0 - error, 1 - ok.
*/

int	put_cell(t_sdl *sdl, t_field *field, int x, int y)
{
	SDL_Rect	cell;

	cell.x = field->border.x + field->cell_shift_x + 1
		+ (x * (field->cell_size.x + 1));
	cell.y = field->border.y + field->cell_shift_y + 1
		+ (y * (field->cell_size.y + 1));
	cell.w = field->cell_size.x;
	cell.h = field->cell_size.y;
	if (SDL_RenderFillRect(sdl->renderer, &cell) < 0)
	{
		return (ft_out_message((char*)SDL_GetError(), 0));
	}
	return (1);
}

/*
** Проход по всем ячейкам.
** @param sdl структура отрисовки.
** @param field структура поля.
** @return 0 - error, 1 - ok.
*/

int	put_cells(t_sdl *sdl, t_field *field)
{
	int	i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (set_color(sdl, field->cells[i].color) < 0)
			return (ft_out_message((char*)SDL_GetError(), 0));
		if (!put_cell(sdl, field, i % field->row_length, i / field->row_length))
			return (0);
	}
	return (1);
}

/*
** Вывод обабатываемой ячейки.
** @param sdl структура отрисовки.
** @param field структура поля.
** @param index индекс ячейки на поле.
** @return 0 - error, 1 - ok.
*/

int	put_current_cell(t_sdl *sdl, t_field *field, int index)
{
	SDL_Rect	cell;
	int			bold;
	int			x;
	int			y;

	bold = field->cell_size.x / 5;
	x = index % field->row_length;
	y = index / field->row_length;
	cell.x = field->border.x + field->cell_shift_x + 1
		+ (x * (field->cell_size.x + 1)) + bold;
	cell.y = field->border.y + field->cell_shift_y + 1
		+ (y * (field->cell_size.y + 1)) + bold;
	cell.w = field->cell_size.x - bold * 2;
	cell.h = cell.w;
	if (set_color(sdl, 7) < 0)
		return (ft_out_message((char*)SDL_GetError(), 0));
	if (!put_border(sdl, cell, bold, 7))
		return (0);
	return (1);
}

/*
** Вывод поля.
** @param sdl структура отрисовки.
** @param field структура поля.
** @return 0 - error, 1 - ok.
*/

int	put_field(t_sdl *sdl, t_field *field)
{
	if (!put_border(sdl, field->border, BOLD_BORDER, 6)
		|| !put_cells(sdl, field))
		return (0);
	if (!put_current_cell(sdl, field, field->carriage_pos))
	{
		return (0);
	}
	return (1);
}
