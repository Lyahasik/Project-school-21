/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:19:54 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/13 00:55:09 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define B_S 1

# include "../libraries/libft/header/libft.h"
# include "corewar_struct.h"
# include "corewar_op.h"

# include <fcntl.h>

# define OP_CODE_LEN				1
# define ARGS_CODE_LEN				1
# define REG_LEN					1

# define MASK_R					0b11000000
# define MASK_G					0b00110000
# define MASK_B					0b00001100
# define MASK_A					0b00000011
# define MASK_SIGIN				0b10000000

static unsigned char			g_type_args[3] = {
	T_REG,
	T_DIR,
	T_IND
};
/*
** Virtual machine funcs
*/

/*
** Memory
*/

t_vm				*vm_create(void);
void				vm_free(t_vm **vm);
unsigned			reverse_bytes(unsigned num);
/*
** Validation, preparation, presentation
*/
void				vm_valid(t_vm *vm, char **input);
char				**valid_flags(t_vm *vm, char **input, int *i, int *count);
char				**valid_filename(t_vm *vm, char **input, int *j,
						int *count);
void				vm_prep(t_vm *vm);
void				prep_presentation(t_vm *vm);
void				sort_players(t_vm *vm);
void				valid_exec_size(t_vm *vm, t_file file, int i);

/*
** war funcs
*/
t_process			*proc_init(int id_player, int addr);
void				proc_insert(t_process **l_proc, t_process *proc);
t_process			*proc_copy(t_process *proc, int addr);
int					get_byte_int(t_vm *vm, int position, int size_reg);
void				put_int_byte(t_vm *vm, int addr, int value, int size);
void				vm_war(t_vm *vm);
void				vm_loop_war(t_vm *vm);
void				get_op_code(t_vm *vm, t_process *proc);
void				vm_print_proc(t_process *proc);
int					mod_position(int position);
void				get_op_type_agrs(t_vm *vm, t_process *proc, t_op *op);
int					vm_valid_args(t_vm *vm, t_process *proc, t_op *op);
int					gap_op_args(t_process *proc, t_op *op);
void				proc_step(t_process *proc);
int					get_op_args(t_vm *vm, t_process *proc, int index_arg,
						int is_mod);
int					get_step(int type_arg, t_op *op);
void				vm_proc_dead(t_vm *vm);
void				print_last_alive(t_vm *vm);
void				vm_print_memory(t_vm *vm);
void				vm_print_hex_test(void *mem, int size);

/*
** Error management
*/

int					put_general(t_sdl *sdl, t_menu *menu, t_vm *vm);
int					put_menu(t_sdl *sdl, t_menu *menu, t_vm *vm);
int					init_players(t_graphic *graphic, t_vm *vm);

/*
** Player
*/

int					put_player(t_vm *vm, SDL_Rect background, int number);

/*
** Carriage
*/

int					put_carriage(t_vm *vm, SDL_Rect background, int id_player);

/*
** Virtual Machine ERROR CODES
** 0 - default
** 1 - no arguments, usage;
** 2 - number of players exceeds MAX_PLAYERS;
** 3 - allocation error
** 4 - wrong file extension
** 5 - cannot open file
** 6 - cannot close file
** 7 - file is empty
** 8 - wrong binary encoding (magic header)
** 9 - execution code is corrupted (wrong size)
** 10 - execution code exceeds CHAMP_MAX_SIZE
*/

void				vm_error(int error_code);

#endif
