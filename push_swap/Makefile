# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 15:27:59 by dhorker           #+#    #+#              #
#    Updated: 2020/11/05 22:34:35 by lyahasik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = checker

PUSH = push_swap

WWW = -Wall -Wextra -Werror

LIB = $(DIR_LIB)libft.a

DIR_LIB = libft/

DIR_GENERAL = general/

DIR_PUSH = push/

DIR_CHECK = check/

SRC_GENERAL =	$(addprefix $(DIR_GENERAL), validity.c operations.c \
				work_elements.c work_blockes.c outputs.c)

SRC_CHECK =	$(addprefix $(DIR_CHECK), main.c run_check.c) \
			$(SRC_GENERAL)

SRC_PUSH =	$(addprefix $(DIR_PUSH), main.c simple_sorting.c work_steps.c work_drums.c displacement.c) \
			$(SRC_GENERAL)

OBJ_GENERAL = $(SRC_GENERAL:.c=.o)

OBJ_CHECK = $(SRC_CHECK:.c=.o)

OBJ_PUSH = $(SRC_PUSH:.c=.o)

all: $(PUSH) $(CHECK)

%.o : %.c
	gcc $(WWW) -I . -I $(DIR_LIB) -I $(DIR_LIB)ft_printf/ -c $^ -o $@

$(LIB):
	make -C libft

$(CHECK): $(LIB) $(OBJ_CHECK)
	gcc $(OBJ_CHECK) $(LIB) $(WWW) -I . -o $(CHECK)

$(PUSH): $(LIB) $(OBJ_PUSH)
	gcc $(OBJ_PUSH) $(LIB) $(WWW) -I . -o $(PUSH)

clean:
	make clean -C libft
	rm -rf *.o
	rm -rf $(DIR_GENERAL)*.o
	rm -rf $(DIR_PUSH)*.o
	rm -rf $(DIR_CHECK)*.o

fclean: clean
	make fclean -C libft
	rm -rf $(CHECK)
	rm -rf $(PUSH)

re: fclean all
