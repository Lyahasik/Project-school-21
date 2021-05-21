/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:00:40 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/14 16:33:13 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct	s_element
{
	int					number;
	int					output;
	int					step_start;
	int					step_destination;
	int					step_total;
	struct s_element	*start;
	struct s_element	*next;
	struct s_element	*previous;
}				t_element;

/*
** Push_swap
*/
void			output_blocks(t_element *block_a, t_element *block_b);
int				count_elements(t_element *block);
t_element		*run_instructions(t_element *block_a, char *instructions);
t_element		*create_alement(char *value, t_element *second_element);
void			transfer_element(int value, t_element *in_start);
void			delete_element(t_element *start);
t_element		*parcer(char **arguments, int checker);
void			output_blocks(t_element *block_a, t_element *block_b);
void			rotate_drum(t_element *rotatable_block, t_element *second_block,
				int quantity, char block_name);
t_element		*search_min_element(t_element *block);
t_element		*min_way(t_element *block_a, t_element *block_b);
void			recount_steps(t_element *to_block, t_element *in_block);
int				check_steps(t_element *to_block, t_element *in_block,
				int rhesus);
t_element		*search_position(int value, t_element *block);
void			push_b(t_element *block_a, t_element *block_b, int let);
void			put_in_place(t_element *block_a, t_element *block_b);
void			operation_s(t_element *block_a, t_element *block_b);
void			operation_p(t_element *to_block, t_element *in_block);
void			operation_r(t_element *block_a, t_element *block_b, int rhesus);
void			sorting_three(t_element *block_a, t_element *block_b);
void			start_simple_sorting(t_element *block_a, t_element *block_b);
int				check_argument(char *argument);
int				check_numbers(char **arguments, t_element *block);
int				check_duplicate(t_element *block);
int				check_instruction(char *instruction);
int				check_sorting(t_element *block_a, t_element *block_b);
char			*remove_space(int av, char **ac);
int				free_block(t_element *block);
void			output_prompt(int checker);
int				find_max(t_element *block);
int				find_min(t_element *block);

#endif
