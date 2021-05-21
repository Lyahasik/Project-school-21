# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 16:47:11 by dhorker           #+#    #+#              #
#    Updated: 2020/11/04 00:59:57 by lyahasik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESULT = ft_printf.o

WWW = -Wall -Wextra -Werror

LIB = ../

SUPP = support/

TYPE = type/

OBJECT =	$(SUPP)specificator.o	$(SUPP)support_1.o	$(SUPP)support_2.o		$(SUPP)ft_atolu.o \
			$(SUPP)ft_itoa_base.o	$(SUPP)ft_output.o	$(SUPP)ft_utoa.o		$(SUPP)out_type_diu.o \
			$(SUPP)out_type_pxo.o	$(SUPP)out_type_u.o	$(SUPP)out_type_big_x.o	$(SUPP)virtual_processing.o \
			\
			$(TYPE)type_di.o	$(TYPE)type_x.o		$(TYPE)type_u.o		$(TYPE)type_x_big.o\
			$(TYPE)type_o.o		$(TYPE)type_p.o		$(TYPE)type_c.o		$(TYPE)type_s.o \
			$(TYPE)type_f_1.o	$(TYPE)type_f_2.o \
			$(TYPE)type_lf_1.o	$(TYPE)type_lf_2.o	$(TYPE)type_lf_3.o	$(TYPE)type_lf_4.o\
			$(TYPE)type_llf_1.o	$(TYPE)type_llf_2.o	$(TYPE)type_llf_3.o	$(TYPE)type_llf_4.o

all: $(RESULT)

%.o : %.c
	gcc $(WWW) -I $(LIB) -I. -c $^ -o $@

$(RESULT): $(OBJECT)
	gcc $(WWW) -I $(LIB) -I. -c ft_printf.c

clean:
	rm -f *.o
	rm -f $(TYPE)*.o
	rm -f $(SUPP)*.o

fclean: clean
	rm -f $(RESULT)

re: fclean all
