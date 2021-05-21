/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:28:08 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/13 00:39:46 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_STRUCT_H
# define COREWAR_STRUCT_H

# include "op.h"
# include "graphic.h"

# define STAGE		vm->stage
# define PLAYER		vm->players
# define PROC		vm->processes
# define DUMP		vm->dump
# define N_PLAYERS	vm->players_num
# define VIS		vm->visualizer

# define PROC_POS	proc->curr_position
# define PROC_STEP	proc->step
# define PROC_REG	proc->reg
# define PROC_TA	proc->type_args

/*
** list of players
*/

typedef struct			s_player
{
	char				*file;
	int					n_on;
	int					n_num;
	int					fd;
	size_t				exec_size;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	int					id_op;
	void				*exec_code;
	int					loop_live;
}						t_player;

/*
** list of proce
*/

typedef struct			s_process
{
	int					id;
	int					carry;
	int					id_op;
	int					cycle_op;
	int					cycle_live;
	int					curr_position;
	size_t				step;
	int					reg[REG_NUMBER];
	int					id_player;
	uint32_t			type_args[3];
	struct s_process	*next;
}						t_process;

/*
** main structure for virtual machine
*/

typedef	struct			s_vm
{
	uint8_t				stage[MEM_SIZE];
	t_player			*players;
	t_process			*processes;
	int					dump;
	int					visualizer;
	int					n_loop_dead;
	int					count_check;
	int					count_live;
	int					players_num;
	int					proc_num;
	int					n_loop;
	int					n_loop_check;
	int					is_aff;
	int					survivor_id;
	t_graphic			*graphic;
}						t_vm;

/*
** structure for file
*/

typedef struct			s_file
{
	size_t				size;
	char				*raw;
}						t_file;

/*
** Events
*/

int						processing_events(t_vm *vm, t_graphic *graphic,
							SDL_Event event);

/*
** Launch
*/

int						launch_graphic(t_vm *vm);

/*
** Rendering
*/

void					rendering(t_vm *vm, t_graphic *graphic, t_sdl *sdl);
int						render_frame(t_vm *vm, t_graphic *graphic, t_sdl *sdl);

#endif
