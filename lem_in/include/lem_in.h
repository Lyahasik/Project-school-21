/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 00:22:45 by jsprouts          #+#    #+#             */
/*   Updated: 2020/12/05 20:38:42 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "libft.h"
# include "SDL.h"
# include <math.h>

# define ERR_MEM		"ERROR: Memory allocation\n"
# define ERR_READ		"ERROR: Reading error occured\n"
# define ERR_OVERSIZE	"ERROR: Oversized map\n"
# define ERR_EMPTY		"ERROR: Empty line\n"
# define ERR_ANTS_NUM	"ERROR: Incorrect number of ants on input\n"
# define ERR_ROOM_SPACE	"ERROR: Rooms spacing\n"
# define ERR_ROOMS_NO	"ERROR: No rooms\n"
# define ERR_ROOMS_INV	"ERROR: Invalid rooms\n"
# define ERR_ROOM_NAME	"ERROR: Invalid room name\n"
# define ERR_ROOM_DNAME	"ERROR: Room name has duplicate\n"
# define ERR_ROOM_DCOOR	"ERROR: Room coords has duplicate\n"
# define ERR_POINT		"ERROR: Wrong point\n"
# define ERR_START_NUM	"ERROR: More than one ##start cmd\n"
# define ERR_START_MISS	"ERROR: Missing ##start\n"
# define ERR_END_NUM	"ERROR: More than one ##end cmd\n"
# define ERR_END_MISS	"ERROR: Missing ##end\n"
# define ERR_COORD		"ERROR: Invalid coord\n"
# define ERR_LINK_DUP	"ERROR: Duplicate links\n"
# define ERR_LINK_INC	"ERROR: Incorrect links\n"
# define ERR_LINK_SPACE	"ERROR: Links spacing\n"
# define ERR_IMG_BACK	"ERROR: Invalid background image\n"
# define ERR_IMG_ANT	"ERROR: Invalid ant image\n"
# define ERR_IMG_ROOM	"ERROR: Invalid room image\n"
# define ERR_SDL_INIT	"ERROR: Failed initialization sdl\n"
# define ERR_SCALE		"ERROR: Oversized scale map\n"

# define AMOUNT_LINES	10
# define MAX_SIZE		400000
# define SIZE_H			720
# define SIZE_W			1080

typedef struct		s_cont
{
	int				id;
	int				ant;
	struct s_cont	*next;
	struct s_cont	*prev;
}					t_cont;

typedef struct		s_path
{
	int				size;
	int				ratio;
	t_cont			*path;
	t_cont			*first;
	t_cont			*last;
	struct s_path	*next;
}					t_path;

typedef struct		s_paths
{
	int				size;
	int				id_path;
	t_cont			*path;
	t_cont			*start;
	struct s_paths	*next;
	struct s_paths	*prev;
}					t_paths;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				is_visit;
	int				id_path;
}					t_room;

typedef struct		s_data
{
	int				is_spaces;
	int				ants_num;
	char			input[MAX_SIZE];
	t_room			*rooms;
	int				rooms_amount;
	int				start;
	int				end;
	int				**connections;
	t_path			*paths;
	int				finished;
	int				is_first;
	int				id_path;
	t_paths			*last_path;
	t_paths			*start_path;
}					t_data;

typedef struct		s_elem
{
	int				i;
	int				id;
	int				id_prev;
	int				isbet;
	int				count;
}					t_elem;

/*
** Parser
** +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

/*
** Parser
*/

int					input_read(t_data *data);
int					reading_map(t_data *data);

/*
** Processing
*/

int					filling_data(t_data *data, char **lines);
int					recording_data(t_data *data);

/*
** Ants
*/

int					skip_ants(char **lines);
int					find_ants(t_data *data, char *line);

/*
** Rooms
*/

int					check_rooms_duplicate(t_data *data);
int					processing_rooms(t_data *data, char *line);
int					filling_rooms(t_data *data, char *line, int *point,
					int *count);

/*
** Connections
*/

int					filling_connections(t_data *data, char *line);
int					processing_connections(t_data *data, char *line);

/*
** Check_input
*/

int					check_line_point(char *line);
int					check_spaces(char *line, char *message);
int					check_line_empty(t_data *data, char **lines);

/*
** Creation
*/

t_data				*create_data();
int					create_rooms(t_data *data, int amount, char *line);
int					create_connections(t_data *data, int amount);

/*
** Freeing
*/

int					free_data(t_data *data);

/*
** Core
** +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

int					compare_and_delete_path(t_paths **elem, t_data *data,
					int diff);
int					check_links_and_del_path(t_paths **paths, t_paths **elem,
					t_data *data);
int					check_size(t_paths *elem, int room);
int					is_better(t_data *data, t_paths **paths, int room,
					int from);
int					choose_path(t_paths *paths, t_data *data);
void				free_path(t_paths **paths, t_data *data);
void				only_one_path(t_paths **paths, t_data *data);
void				delete_path(t_paths **paths, t_data *data);
void				to_zero_id_path(t_data *data);
void				clean_path(t_data *data, t_paths *paths);
void				add_room(t_data *data, t_paths *paths, int i,
					int *count_end);
void				create_new_path(t_data *data, t_paths *paths, int room,
					int *count_end);
t_paths				*init(int id_path, int room, t_data *data);
void				create_path(t_data *data, t_paths **paths, int room,
					t_paths **start);
void				run_ant(t_data data, int *ant, int *finished);
void				move_ant(t_data *data, t_cont *curr, t_path *c_path);
void				move_possible(t_data *data);
void				count_ratio(t_data data);
void				move_ants(t_data data);
int					is_back(t_data *data, t_paths **paths, int id, int count);
int					no_ways(t_data *data);
int					to_much(t_data *data);
void				free_paths(t_path *paths);
void				error_case(void *to_free);
void				print_line(char *line);
void				print_ant_step(char *ant, char *room);
t_path				*form_path(int i, t_data data);
void				find_pos(t_path *ret, t_path *cur);
void				first_three_paths(t_path **last, t_path **ret, t_path *cur);
t_path				*get_paths(t_data data);
int					is_exit(t_data *data, int *count_end, t_paths *paths);
void				step_in_paths(t_data *data);
void				bfs_shortest_path(t_data *data);
int					conditions(t_data *data, t_elem *elem, t_paths **paths,
					int *count_end);
void				next_room(t_data *data, t_paths **paths, int *count_end);
void				init_path(t_data data, t_path **ret, t_cont **path, int i);
void				init_node_links(t_cont **path, int k);
void				*ft_palloc(size_t i);
void				out_one_step(int i, char *name);

/*
** Graphic
** +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

typedef struct		s_vector
{
	int				x;
	int				y;
}					t_vector;

typedef struct		s_ant
{
	char			*name;
	t_vector		position;
	t_vector		destination;
	int				room_current;
	int				room_destination;
}					t_ant;

typedef struct		s_img
{
	SDL_Texture		*img;
	int				height;
	int				width;
}					t_img;

typedef struct		s_graphic
{
	t_data			*data;
	t_ant			**steps;
	int				steps_amount;
	int				*step_ants_amount;
	t_ant			*ants;
	int				scale[11];
	int				scale_i;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*background;
	t_img			ant;
	t_img			room;
}					t_graphic;

/*
** Parser
*/

int					reading_result(t_graphic *graphic);

/*
** Creation
*/

int					create_steps(t_graphic *graphic);
t_graphic			*create_graphic();
int					create_ants(t_graphic *graphic);

/*
** Freeing
*/

void				free_graphic(t_graphic *graphic);

/*
** Rooms
*/

int					put_rooms(t_graphic *graphic, t_room *rooms);
t_vector			find_coordinate(t_data *data, int room);
int					find_room(t_data *data, char **ant);

/*
** Connections
*/

int					put_path(t_graphic *graphic);

/*
** Ants
*/

t_ant				*find_ant(t_graphic *graphic, char *name);

/*
** Coordinates
*/

int					calculation_scale(t_graphic *graphic);

/*
** Sdl_launch
*/

int					window_launch(t_graphic *graphic);

/*
** Events
*/

int					event_escape(SDL_Event event);

/*
** Init_textures
*/

int					init_background(t_graphic *graphic);
int					init_ant(t_graphic *graphic);
int					init_room(t_graphic *graphic);

/*
** Put_textures
*/

int					put_ant(t_graphic *graphic, t_img img, t_vector point);
int					scale_point(t_graphic *graphic, int number);
int					put_background(t_graphic *graphic);
int					put_image(t_graphic *graphic, t_img img, int x, int y);

/*
** Vectors
*/

int					equals_vector(t_vector vector1, t_vector vector2);
t_vector			create_vector(int x, int y);

/*
** Steps
*/

int					put_steps(t_graphic *graphic, int *step);

/*
** Move_line
*/

int					put_shift(t_graphic *graphic, t_ant *ant,
					t_room current, t_room destination);

#endif
