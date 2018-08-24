# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstreak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 11:33:03 by lstreak           #+#    #+#              #
#    Updated: 2018/07/10 11:33:09 by lstreak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

LIB = libftprintf.a

INC_DIR = includes

CC = gcc -w

CFLAGS = -I$(INC_DIR)

SOURCES = 	conv_spec.c\
			ft_print.c\
			ft_utils.c\
			ft_utils2.c\
			ft_utils3.c\
			ft_printf.c\
			ft_isdigit.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_strdup.c\
			ft_strlen.c\
			ft_strcpy.c\
			ft_init_struc.c\
			ft_init_struc2.c\
			ft_mod_arg.c\
			ft_toupper.c\
			ft_atoi.c\
			ft_strjoin.c\
			ft_isascii.c\
			ft_tolower.c\
			ft_strsub.c\
			ft_ibull.c\
			ft_putwchar_fd.c\
			ft_putchar_fd.c\
			ft_putnwstr.c\
			ft_getwtchar_fd.c\
			ft_wchar.c\
			ft_strmod.c\
			ft_putnbr.c\
			ft_f1.c\
			ft_f2.c\
			ft_f3.c\
			ft_f4.c\
			ft_f5.c\
			ft_f6.c

SRC = $(addprefix sources/,$(SOURCES))

OBJ = $(SRC:.c=.o)

all : $(NAME) $(LIB)

$(NAME) : $(LIB)
	@$(CC) -o $(NAME) main.c $(LIB) $(CFLAGS)
	@echo "MiniOns Arrived!"
	@echo "A New Challenger!"

$(LIB) : $(OBJ)
	@ar -r $(LIB) $(OBJ)
	@ranlib $(LIB)
	@echo "Cpt. Alum1 Lib. Arrived."

clean :
	@rm -rf $(OBJ)
	@echo "MiniOns Died!"

fclean : clean
	@rm -rf $(NAME) $(LIB)
	@echo "All's Destroyed! R.I.P :'("

re : fclean all
	@echo "And The Rain Against! ^^"

.PHONY: all clean fclean re
