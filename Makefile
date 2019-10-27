# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hseffian <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 18:38:31 by hseffian          #+#    #+#              #
#    Updated: 2019/10/27 10:34:59 by zael-mab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT_PATH = ./srcs/get_next_line/libft/
LIB = -lmlx -framework OpenGL -framework  AppKit
SRC = 	srcs/main.c\
		srcs/get_pos.c\
		srcs/draw.c\
		srcs/draw_line.c\
		srcs/keyhooks.c\
		srcs/free.c\
		srcs/error.c\
		srcs/get_next_line/get_next_line.c\

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	gcc $(OBJ) $(LIB) $(LIBFT_PATH)/libft.a -o $(NAME)
$(OBJ): %.o : %.c
	gcc $(FLAGS) -c $< -o $@
clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ)
fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)
re: fclean all
