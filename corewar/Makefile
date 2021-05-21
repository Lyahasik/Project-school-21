# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 14:04:51 by slynell           #+#    #+#              #
#    Updated: 2021/01/14 07:33:15 by jsprouts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm

VM = corewar

CC = gcc

FLAGS = -Wall  -Werror -Wextra -g

PATH_SDL := $(PWD)/libraries/SDL/SDL2-2.0.12

SDL = $(PWD)/libraries/SDL/SDL2-2.0.12/sdl2-config

SDL_FLAG := `./libraries/SDL/SDL2-2.0.12/sdl2-config --libs --cflags` -O0 -lm
# -Wall -Werror -Wextra -O2

# /*
# ** ========================== HEADER ==============================
# */
INCS_VM = corewar.h corewar_op.h corewar_struct.h graphic.h op.h
INCS_ASM = asm.h error.h op.h
IDIR = header
LDIR = libraries/libft
INCS += $(addprefix $(LDIR)/,$(addprefix $(IDIR)/,$(libft.h)))
INCLUDES_VM = $(addprefix $(IDIR)/,$(INCS_VM))
INCLUDES_ASM = $(addprefix $(IDIR)/,$(INCS_ASM))

LIBFT = $(addprefix $(LDIR)/,libft.a)

# /*
# ** ====================== SOURCE  MAIN ==========================
# */
SDIR = src
ODIR = obj

# /*
# ** ====================== SOURCE ASM ==========================
# */
SDIR_ASM = src/asm
ODIR_ASM = obj/asm

SRC_ASM = asm_arg_get.c
SRC_ASM += asm_arg_set.c
SRC_ASM += asm_basic.c
SRC_ASM += asm_check.c
SRC_ASM += asm_get_labels.c
SRC_ASM += asm_get_name.c
SRC_ASM += asm_instructions.c
SRC_ASM += asm_main.c
SRC_ASM += asm_output.c
SRC_ASM += asm_set_labels.c
SRC_ASM += asm_tools.c


SOURCES_ASM = $(addprefix $(SDIR_ASM)/,$(SRC_ASM))
OBJECTS_ASM = $(addprefix $(ODIR_ASM)/,$(SRC_ASM:.c=.o))

# /*
# ** ====================== SOURCE VM ==========================
# */
SDIR_VM = src/vm
ODIR_VM = obj/vm

SRC_VM = vm_main.c
SRC_VM += vm_war.c
SRC_VM += vm_bytes.c
SRC_VM += vm_print.c
SRC_VM += vm_op.c
SRC_VM += vm_proc.c
SRC_VM += vm_valid_args.c
SRC_VM += vm_proc_dead.c
SRC_VM += utils.c


SOURCES_VM = $(addprefix $(SDIR_VM)/,$(SRC_VM))
OBJECTS_VM = $(addprefix $(ODIR_VM)/,$(SRC_VM:.c=.o))

# /*
# ** ====================== SOURCE VM_INIT ==========================
# */
SDIR_VM_INIT = src/vm/vm_init
ODIR_VM_INIT = obj/vm/vm_init

SRC_VM_INIT = vm_create.c
SRC_VM_INIT += vm_error.c
SRC_VM_INIT += vm_free.c


SOURCES_VM_INIT = $(addprefix $(SDIR_VM_INIT)/,$(SRC_VM_INIT))
OBJECTS_VM_INIT = $(addprefix $(ODIR_VM_INIT)/,$(SRC_VM_INIT:.c=.o))

# /*
# ** ====================== SOURCE VM_PARSE ==========================
# */
SDIR_VM_PARSE = src/vm/vm_parse
ODIR_VM_PARSE = obj/vm/vm_parse

SRC_VM_PARSE = vm_preparation.c
SRC_VM_PARSE += vm_preparation_help.c
SRC_VM_PARSE += vm_validation.c
SRC_VM_PARSE += vm_validation_help.c


SOURCES_VM_PARSE = $(addprefix $(SDIR_VM_PARSE)/,$(SRC_VM_PARSE))
OBJECTS_VM_PARSE = $(addprefix $(ODIR_VM_PARSE)/,$(SRC_VM_PARSE:.c=.o))


# /*
# ** ====================== SOURCE VM_OP ==========================
# */
SDIR_VM_OP = src/vm/vm_op
ODIR_VM_OP = obj/vm/vm_op

SRC_VM_OP = op_live.c
SRC_VM_OP += op_ld.c
SRC_VM_OP += op_st.c
SRC_VM_OP += op_add.c
SRC_VM_OP += op_sub.c
SRC_VM_OP += op_and.c
SRC_VM_OP += op_or.c
SRC_VM_OP += op_xor.c
SRC_VM_OP += op_zjmp.c
SRC_VM_OP += op_ldi.c
SRC_VM_OP += op_sti.c
SRC_VM_OP += op_fork.c
SRC_VM_OP += op_lld.c
SRC_VM_OP += op_lldi.c
SRC_VM_OP += op_lfork.c
SRC_VM_OP += op_aff.c


SOURCES_VM_OP = $(addprefix $(SDIR_VM_OP)/,$(SRC_VM_OP))
OBJECTS_VM_OP = $(addprefix $(ODIR_VM_OP)/,$(SRC_VM_OP:.c=.o))

# /*
# ** ====================== SOURCE GRAPHIC ==========================
# */
SDIR_GRAPHIC = src/graphic
ODIR_GRAPHIC = obj/graphic

SRC_GRAPHIC = launch.c
SRC_GRAPHIC += allocation.c
SRC_GRAPHIC += init.c
SRC_GRAPHIC += freeing.c
SRC_GRAPHIC += field.c
SRC_GRAPHIC += menu.c
SRC_GRAPHIC += rendering.c
SRC_GRAPHIC += events.c
SRC_GRAPHIC += color.c
SRC_GRAPHIC += player.c
SRC_GRAPHIC += man.c
SRC_GRAPHIC += number.c
SRC_GRAPHIC += textures.c
SRC_GRAPHIC += carriage.c
SRC_GRAPHIC += general.c

SOURCES_GRAPHIC = $(addprefix $(SDIR_GRAPHIC)/,$(SRC_GRAPHIC))
OBJECTS_GRAPHIC = $(addprefix $(ODIR_GRAPHIC)/,$(SRC_GRAPHIC:.c=.o))

.PHONY: clean fclean all re $(LIBFT)

all : $(LIBFT) $(VM) $(ASM) Makefile
	@2> tmp.log
	@@echo "Programms $(VM) $(ASM) build successfully \c" >> tmp.log

$(VM) : $(LIBFT) $(INCLUDES_VM) $(SDL) $(OBJECTS_VM) $(OBJECTS_VM_INIT) $(OBJECTS_VM_PARSE) $(OBJECTS_VM_OP) $(OBJECTS_GRAPHIC)
	@$(CC) $(FLAGS) -o $(VM) $(OBJECTS_VM) $(OBJECTS_VM_INIT) $(OBJECTS_VM_PARSE) $(OBJECTS_VM_OP) $(OBJECTS_GRAPHIC)  -I $(IDIR) $(LIBFT) $(SDL_FLAG)
	@echo "\nProgramm $(VM) build successfully \033[32m[OK]\033[0m\n"

$(ASM) : $(LIBFT) $(OBJECTS_ASM) $(INCLUDES_ASM)
	@$(CC) $(FLAGS) -o $(ASM) $(OBJECTS_ASM) -I $(IDIR) $(LIBFT)
	@echo "\nProgramm $(ASM) build successfully \033[32m[OK]\033[0m\n"

# /*
# ** ====================== MAKE LIBFT ==========================
# */
$(LIBFT) : Makefile
	@make -C $(LDIR) 2> tmp.log

# /*
# ** ====================== MAKE SDL ==========================
# */
$(SDL):
	cd $(PATH_SDL); ./configure --prefix=$(PATH_SDL); make;
	make -sC $(PATH_SDL) install

# /*
# ** ====================== MAKE ASM ==========================
# */
$(ODIR_ASM)/%.o : $(SDIR_ASM)/%.c $(INCLUDES_ASM)
	@if [[ $< == src/asm/asm_arg_get.c ]]; then \
		echo "\n > Make \033[33m.asm\t\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR) 2> tmp.log
	@mkdir -p $(ODIR_ASM) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** =================== MAKE VM_OP ========================
# */
$(ODIR_VM_OP)/%.o : $(SDIR_VM_OP)/%.c $(INCLUDES_VM)
	@if [[ $< == src/vm/vm_op/op_live.c ]]; then \
		echo "\n > Make \033[33mvm op\t\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_VM_OP) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** =================== MAKE GRAPHIC ========================
# */
$(ODIR_GRAPHIC)/%.o : $(SDIR_GRAPHIC)/%.c $(INCLUDES_VM)
	@if [[ $< == src/graphic/launch.c ]]; then \
		echo "\n > Make \033[33mgraphic\t\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR) 2> tmp.log
	@mkdir -p $(ODIR_GRAPHIC) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** =================== MAKE VM_PARSE ========================
# */
$(ODIR_VM_PARSE)/%.o : $(SDIR_VM_PARSE)/%.c $(INCLUDES_VM)
	@if [[ $< == src/vm/vm_parse/vm_preparation.c ]]; then \
		echo "\n > Make \033[33mvm parse\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR) 2> tmp.log
	@mkdir -p $(ODIR_VM_PARSE) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** =================== MAKE VM_INIT ========================
# */
$(ODIR_VM_INIT)/%.o : $(SDIR_VM_INIT)/%.c $(INCLUDES_VM)
	@if [[ $< == src/vm/vm_init/vm_create.c ]]; then \
		echo "\n > Make \033[33mvm init\t\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR) 2> tmp.log
	@mkdir -p $(ODIR_VM_INIT) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** ====================== MAKE VM ==========================
# */
$(ODIR_VM)/%.o : $(SDIR_VM)/%.c $(INCLUDES_VM)
	@if [[ $< == src/vm/vm_main.c ]]; then \
		echo "\n > Make \033[33mvm\t\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR) 2> tmp.log
	@mkdir -p $(ODIR_VM) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

clean:
	@make clean -C $(LDIR) 2> tmp.log
	@rm -rf $(ODIR) 2> tmp.log
 
fclean: clean
	@make fclean -C $(LDIR) 2> tmp.log
	@rm -rf $(VM) 2> tmp.log
	@echo "\033[31m> Clear $(VM)\033[0m"
	@rm -rf $(ASM) 2> tmp.log
	@echo "\033[31m> Clear $(ASM)\033[0m"

re: fclean all
