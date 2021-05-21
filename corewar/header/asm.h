/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:36:18 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/10 14:06:39 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "op.h"
# include "error.h"
# include "../libraries/libft/header/libft.h"

# define A 200
# define B 610
# define C 150
# define D 111
# define E 111
# define F 771
# define G 771
# define H 771
# define I 200
# define J 731
# define K 173
# define L 200
# define M 610
# define N 731
# define O 200
# define P 100
# define T_DIR_SIZE	(int[]){0, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4}
# define ARGS_QTY	(int[]){0, 1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1}
# define OCTAL		(int[]){0, 0, 1, 1, 1, 1, 1, 1 ,1, 0, 1, 1, 0, 1, 1, 0, 1}
# define ARGS_TYPES	(int[]){0, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P}
# define ALLOWED_ARG_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789-:%"
# define ALLOWED_DIR_CHARS		"0123456789-"
# define MAX_ARG				3
# define ALT_COMMENT_CHAR		';'

typedef struct	s_operation
{
	int					unique_id;
	int					instruction_id;
	int					position;
	int					octet;
	int					arg[MAX_ARG];
	int					arg_type[MAX_ARG];
	int					arg_is_label[MAX_ARG];
	int					arg_size[MAX_ARG];
	int					size;
	struct s_operation	*next;
}				t_operation;

typedef struct	s_label
{
	char				*name;
	int					unique_id;
	int					position;
	struct s_label		*next;
}				t_label;

typedef struct	s_data
{
	char				*name;
	char				*comment;
	int					fd_r;
	int					fd_w;
	int					full_size;
	unsigned			line_num;
	t_operation			*op;
	t_label				*label;
}				t_data;

void			basic_transformations(t_data *data);
int				clean_line(t_data *data, char **dst);
int				is_instruction(char *s);
int				get_instruction(t_data *data, char **tmp,
								int inst_id, int tmp_len);
int				get_arguments(t_operation *op, char **argv,
								int argc, t_data *data);
int				set_arguments(t_operation *op, char **clean_args,
								int allowed_types, int args_qty);
void			my_check(t_data *data);
int				get_labels_instructions(t_data *data, char *str);
int				get_label(t_data *data, char **tmp, int tmp_len);
int				is_label(char *s);
void			get_name_commit(t_data *data);
void			write_data(t_data *data);
t_label			*set_label(t_label **label, char *str);
t_data			*get_data(t_data *data);
void			free_str_arr(char **str, char ***arr, int flag);
char			*add_spaces(char **str);
char			*set_output_name(char *s);
void			free_data(t_data *data);
void			free_data(t_data *data);
#endif
