/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_freeing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:28:34 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/05 20:32:31 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Завершение работы sdl.
** @param graphic указатель для работы с данными графики.
*/

static void	free_sdl(t_graphic *graphic)
{
	if (graphic->renderer)
		SDL_DestroyRenderer(graphic->renderer);
	if (graphic->window)
		SDL_DestroyWindow(graphic->window);
	if (graphic->background)
		SDL_DestroyTexture(graphic->background);
	if (graphic->ant.img)
		SDL_DestroyTexture(graphic->ant.img);
	if (graphic->room.img)
		SDL_DestroyTexture(graphic->room.img);
	SDL_Quit();
}

/*
** Освобождение памяти для двумерного массива с шагами.
** @param graphic указатель для работы с данными графики.
*/

static void	free_steps(t_graphic *graphic)
{
	int	i;
	int	j;

	if (graphic->steps != NULL)
	{
		i = -1;
		while (graphic->steps[i] != NULL && ++i < graphic->steps_amount)
		{
			j = -1;
			while (++j < graphic->step_ants_amount[i])
			{
				if (graphic->steps[i][j].name != NULL)
					free(graphic->steps[i][j].name);
			}
			free(graphic->steps[i]);
		}
		free(graphic->steps);
	}
}

/*
** Освобождение памяти для данных графики.
** @param graphic указатель для работы с данными графики.
*/

void		free_graphic(t_graphic *graphic)
{
	int	i;

	if (graphic != NULL)
	{
		if (graphic->ants != NULL)
		{
			i = -1;
			while (++i < graphic->data->ants_num)
			{
				if (graphic->ants[i].name)
					free(graphic->ants[i].name);
			}
			free(graphic->ants);
		}
		if (graphic->data != NULL)
		{
			free_data(graphic->data);
		}
		free_steps(graphic);
		free(graphic->step_ants_amount);
		free_sdl(graphic);
		free(graphic);
	}
}
