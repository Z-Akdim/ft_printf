# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 12:15:16 by zakdim            #+#    #+#              #
#    Updated: 2020/01/18 18:21:37 by zakdim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c \
	  ft_printf_utils.c \
	  ft_printf_utils2.c \
	  ft_check_width_precesion.c \
	  check_specefier.c \
      ft_hex.c \
	  ft_flag_s_and_c.c \
	  ft_flag_d_and_u.c \
	  ft_flag_x_and_p.c

OBJ = $(SRC:.c=.o)

all	: $(NAME)
$(NAME) : $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	 
clean : 
	rm -f $ $(OBJ)
fclean : 
	rm -f $(NAME)
	rm -f $ $(OBJ)

re	: fclean all clean
