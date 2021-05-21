/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:19:54 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/09 17:15:04 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H

# define GRAPHIC_H

# include "../libraries/libft/header/libft.h"
# include "../libraries/SDL/SDL2-2.0.12/include/SDL.h"
# include <math.h>

# define ERR_MEM		"ERROR: Memory allocation\n"
# define ERR_SDL_INIT	"ERROR: Failed initialization sdl\n"
# define ERR_COL		"ERROR: Color not set\n"
# define ERR_CELL_NUM	"ERROR: Too many cells\n"
# define ERR_IMG_LOAD	"ERROR: Image loading\n"
# define ERR_PLRS_NUM	"ERROR: Number of players more than 4\n"

# define SIZE_H			720
# define SIZE_W			1080
# define MENU_W			355
# define SHIFT			5
# define BOLD_BORDER	5

# define DELAY_ONE		10
# define DELAY_TWO		50
# define DELAY_THREE	100

/*
**						R		G		B		A
*/

# define RED			210,	54,		54,		255
# define GREEN			8,		166,	34,		255
# define BLUE			55,		55,		255,	255
# define TURQUOISE		39,		227,	194,	255
# define DBLUE			19,		18,		71,		255
# define GREY			136,	136,	136,	255
# define WHITE			207,	207,	207,	255
# define YELLOW			191,	194,	54,		255

typedef struct		s_vector
{
	int				x;
	int				y;
}					t_vector;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_sdl;

typedef struct		s_menu
{
	SDL_Rect		background;
	SDL_Texture		*operations[16];
	SDL_Texture		*text[13];
	SDL_Texture		*figures[10];
}					t_menu;

typedef struct		s_cell
{
	int				color;
}					t_cell;

typedef struct		s_field
{
	SDL_Rect		border;
	t_cell			*cells;
	t_vector		cell_size;
	int				cell_shift_x;
	int				cell_shift_y;
	int				row_length;
	int				carriage_pos;
}					t_field;

typedef struct		s_graphic
{
	t_sdl			*sdl;
	t_menu			*menu;
	t_field			*field;
	short			delay;
	short			stop;
}					t_graphic;

/*
** Allocation
*/

t_graphic			*allocation_graphic();
t_sdl				*allocation_sdl();
t_menu				*allocation_menu();
t_field				*allocation_field();

/*
** Freeing
*/

int					free_graphic(t_graphic *graphic);

/*
** Init
*/

t_graphic			*init_graphic(t_graphic *graphic);

/*
** Color
*/

int					set_color(t_sdl *sdl, int color);

/*
** Field
*/

int					put_border(t_sdl *sdl, SDL_Rect border, int bold,
					int color);
int					put_field(t_sdl *sdl, t_field *field);

/*
** Man
*/

int					put_man(t_sdl *sdl, t_menu *menu);

/*
** Number
*/

int					put_number(t_sdl *sdl, t_menu *menu, SDL_Rect dst,
					int number);

/*
** Textures
*/

int					init_operations(t_menu *menu, SDL_Renderer *renderer);

/*
** Events
*/

int					init_text(t_menu *menu, SDL_Renderer *renderer);
int					init_figures(t_menu *menu, SDL_Renderer *renderer);

/*
** General
*/

int					put_current_cell(t_sdl *sdl, t_field *field, int index);

#endif
