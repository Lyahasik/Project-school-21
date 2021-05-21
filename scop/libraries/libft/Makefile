# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 14:53:48 by dhorker           #+#    #+#              #
#    Updated: 2021/01/04 23:53:53 by lyahasik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =		-Wall -Wextra -Werror
NAME =		libft.a

FT_OBJ =	ft_memset.o\
			ft_bzero.o\
			ft_memcpy.o\
			ft_memccpy.o\
			ft_memmove.o\
			ft_memchr.o\
			ft_memcmp.o\
			ft_strlen.o\
			ft_strdup.o\
			ft_strcpy.o\
			ft_strncpy.o\
			ft_strcat.o\
			ft_strncat.o\
			ft_strlcat.o\
			ft_strchr.o\
			ft_strrchr.o\
			ft_strstr.o\
			ft_strnstr.o\
			ft_strcmp.o\
			ft_strncmp.o\
			ft_atoi.o\
			ft_isalpha.o\
			ft_isdigit.o\
			ft_isalnum.o\
			ft_isascii.o\
			ft_isprint.o\
			ft_toupper.o\
			ft_tolower.o\
			ft_memalloc.o\
			ft_memdel.o\
			ft_strnew.o\
			ft_strdel.o\
			ft_strclr.o\
			ft_striter.o\
			ft_striteri.o\
			ft_strmap.o\
			ft_strmapi.o\
			ft_strequ.o\
			ft_strnequ.o\
			ft_strsub.o\
			ft_strjoin.o\
			ft_strtrim.o\
			ft_strsplit.o\
			ft_itoa.o\
			ft_putchar.o\
			ft_putstr.o\
			ft_putendl.o\
			ft_putnbr.o\
			ft_putchar_fd.o\
			ft_putstr_fd.o\
			ft_putendl_fd.o\
			ft_putnbr_fd.o\
			ft_lstnew.o\
			ft_lstdelone.o\
			ft_lstdel.o\
			ft_lstadd.o\
			ft_lstiter.o\
			ft_lstmap.o\
			ft_strctrim.o\
			ft_sepchar.o\
			ft_putbyte1.o\
			ft_putbyte2.o\
			ft_putbyte4.o\
			ft_lstdelcut.o\
			ft_delmass.o\
			ft_swap.o\
			ft_numlen.o\
			ft_str_char_count.o\
			ft_min.o\
			ft_max.o\
			ft_abs.o\
			ft_check_atoi_int.o\
			get_next_line.o\
			ft_mem_free_two.o\
			ft_out_message.o\
			ft_mem_free_args.o\
			ft_numset.o\
			ft_put_matrix_int.o\
			ft_lines_count.o

HDR = libft.h
HDR_DIR = ./
HDRS = $(addprefix $(HDR_DIR), $(HDR))

all: $(NAME)

$(NAME): $(FT_OBJ)
	ar rc $(NAME) $(FT_OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(FT_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o : %.c $(HDRS)
	gcc $(FLAGS) -c -o $@ $<
