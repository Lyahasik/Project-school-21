# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/03 21:28:36 by lyahasik          #+#    #+#              #
#    Updated: 2021/01/16 15:19:19 by dhorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN	= scop

# /*
# ** ========================== FLAGS ==============================
# */

WW = -Wall -Wextra -Werror
GL_LINUX = -lm -ldl -lGL -lGLU -lX11 -lpthread
GL_MACOS = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# /*
# ** ========================== HEADERS ==============================
# */

HSCOP = ./includes/scop.h
HVECTORS = ./includes/vectors.h
HMATRICES = ./includes/matrices.h
HMESSAGES = ./includes/messages.h

HEADERS =	$(HMATRICES) \
			$(HMESSAGES) \
			$(HVECTORS) \
			$(HSCOP)

# /*
# ** ========================== INCLUDES ==============================
# */

IROOT = -I ./includes/
ILIBFT = -I ./libraries/libft/
IGLEW = -I ./libraries/GLEW/include/GL/
IGLFW = -I ./libraries/GLFW/include/GLFW/

INCLUDES = $(IROOT) $(ILIBFT) $(IGLEW) $(IGLFW)

# /*
# ** ========================== LIBRARIES ==============================
# */

LDIR = ./libraries/

LLIBFT = $(LDIR)libft/libft.a
LGLEW = $(LDIR)GLEW/lib/libGLEW.a
LGLFW = $(LDIR)GLFW/src/libglfw3.a

LIBRARIES = $(LLIBFT) $(LGLEW) $(LGLFW)

# /*
# ** ========================== OBJECTS ==============================
# */

ODIR = ./sources/

UTILS =		$(addprefix $(ODIR)utils/, \
			main.o \
			initializations.o \
			shutdown.o)

WINDOW =	$(addprefix $(ODIR)window/, \
			events.o \
			rendering.o)

GEOMETRY =	$(addprefix $(ODIR)geometry/, \
			transformations.o \
			update_center.o \
			triagle.o \
			objects.o)

VECTORS =	$(addprefix $(ODIR)geometry/vectors/, \
			vector.o \
			normalize.o \
			inversion.o \
			cross.o \
			sum.o \
			division.o \
			length.o)

MATRICES =	$(addprefix $(ODIR)geometry/matrices/, \
			matrix.o \
			model.o \
			multiplication.o \
			projection.o \
			rotation.o \
			scaling.o \
			sum.o \
			translation.o \
			conversions.o \
			view.o)

SHADERS =	$(addprefix $(ODIR)shaders/, \
			shaders_program.o \
			shaders.o)

PARSING =	$(addprefix $(ODIR)parsing/, \
			bmp.o \
			obj.o )

OBJECTS =	$(UTILS) \
			$(WINDOW) \
			$(VECTORS) \
			$(MATRICES) \
			$(GEOMETRY) \
			$(SHADERS) \
			$(PARSING)

# /*
# ** ========================== COMPILE ==============================
# */

all: $(BIN)

gl:
	cd libraries/GLEW; make;
	cd libraries/GLFW; cmake -G "Unix Makefiles"; make;

$(LLIBFT): FORCE
	@make -sC $(LDIR)libft/

FORCE:			;

$(BIN): $(LLIBFT) $(OBJECTS)
	gcc -g $(OBJECTS) $(INCLUDES) $(LIBRARIES) $(GL_MACOS) -o $(BIN)

%.o : %.c $(HEADERS)
	gcc -g $(WWW) $(INCLUDES) -c -o $@ $<

clean:
	rm -rf $(OBJECTS)
	@make clean -sC $(LDIR)libft/

fclean: clean
	rm -rf $(BIN)
	@make fclean -sC $(LDIR)libft/

re: fclean all
