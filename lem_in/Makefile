# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 23:13:16 by jsprouts          #+#    #+#              #
#    Updated: 2020/12/05 23:04:55 by jsprouts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ALG = lem-in

GRAPH = graphic

PATH_SDL := $(PWD)/libraries/SDL2-2.0.12

SDL_CONF = $(PWD)/libraries/SDL2-2.0.12/sdl2-config

SDL_FLAG := `./libraries/SDL2-2.0.12/sdl2-config --libs --cflags` -O0 -lm

WWW = -Wall -Wextra -Werror

DIR_SOURCES = sources/

DIR_LIBFT = libraries/libft/

DIR_SDL = libraries/SDL2/

LIBFT_LNK = -L $(DIR_LIBFT) -lft

LIBFT = $(DIR_LIBFT)/libft.a

PARS =	connections.c \
		ants.c \
		rooms.c \
		check_input.c \
		creation.c \
		freeing.c \
		parser.c \
		processing.c \

SRCA =	my_check.c \
		my_clean.c \
		my_init_create.c \
		my_move.c \
		my_exit.c \
		my_free.c \
		my_output.c \
		my_path.c \
		my_step.c \
		my_init_help.c \
		main.c

SRCG =	graph_main.c \
		graph_ants.c \
		graph_vectors.c \
		graph_parser.c \
		graph_freeing.c \
		graph_creation.c \
		graph_coordinates.c \
		graph_rooms.c \
		graph_connections.c \
		graph_sdl_launch.c \
		graph_events.c \
		graph_init_textures.c \
		graph_put_textures.c \
		graph_steps.c \
		graph_move_line.c

OBJ_DIR = obj/
OBJ_ALG = $(patsubst %.c, %.o, $(SRCA) $(PARS))
OBJA = $(addprefix $(OBJ_DIR), $(OBJ_ALG))
OBJ_GRAPH = $(patsubst %.c, %.o, $(SRCG) $(PARS))
OBJG = $(addprefix $(OBJ_DIR), $(OBJ_GRAPH))

HDRS = lem_in.h
HDR_DIR = include/
HDR = $(addprefix $(HDR_DIR), $(HDRS))

INCLUDES = -I $(HDR_DIR) -I $(DIR_LIBFT) -I $(DIR_SDL)

.PHONY: clean all re fclean

S_CLN = \033[K
C_RED = \033[31m
C_GRN = \033[32m
C_CYAN = \033[36m

all: $(ALG)

$(ALG): $(LIBFT) $(OBJA)
	@gcc $(WWW) -o $(ALG) $(INCLUDES) $(OBJA) $(LIBFT_LNK)
	@printf "\r$(S_CLN)$(C_GRN)Lem-in compiled\n"
	@echo ""
	@echo "\033[92m_/﹋\_\033[0m"
	@echo "\033[92m(҂'_')\033[0m"
	@echo "\033[92m<,︻╦╤─\033[0m"
	@echo "\033[92m /﹋\███████]========COMPILED\033[0m"
	@echo "\033[92m▄▅█████████▅▄▃▂\033[0m"
	@echo "\033[92m█★★ RUSSIA ★★█ █]\033[0m"
	@echo "\033[92m◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤\033[0m"

$(SDL_CONF):
	cd $(PATH_SDL); ./configure --prefix=$(PATH_SDL); make;
	make -sC $(PATH_SDL) install

$(GRAPH): $(LIBFT) $(OBJG) $(SDL_CONF)
	@gcc $(WWW) -o $(GRAPH) $(INCLUDES) $(OBJG) $(LIBFT_LNK) $(SDL_FLAG)

FORCE:			;

$(LIBFT): FORCE
	@make -sC $(DIR_LIBFT)

$(OBJ_DIR)%.o: $(DIR_SOURCES)%.c $(HDR)
	@mkdir -p $(OBJ_DIR)
	@printf "\r$(S_CLN)$(C_CYAN)Compiling$(S_CLN) $(ALG)"
	@gcc $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
	@make clean -sC $(DIR_LIBFT)
	@printf "$(C_RED)Remove lem-in *.o\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(ALG)
	@printf "$(C_RED)Remove $(ALG)\n"
	@make -sC $(DIR_LIBFT) fclean

re: fclean all
