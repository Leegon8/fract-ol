# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 15:48:56 by lauriago          #+#    #+#              #
#    Updated: 2024/07/03 10:30:35 by lauriago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = fractal.c render.c set_init.c utils.c mandelbrot.c hooks.c colors.c \
	julia.c colors2.c
SRC_PATH = ./src/
OBJ_PATH = ./obj/
OBJ  = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
H_PATH = ./inc/
HEADERS = -I$(H_PATH)

RM = rm -f
CC = gcc -fsanitize=address
FLAGS = -g -Wall -Wextra -Werror
LINKS = -Llibft -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT = libft/libft.a
#MLX = mlx/libmlx.a
MLX_LINUX = mlx_linux/libmlx.a
#LINKS = -I libft -L libft \
		-Lmlx -lmlx -framework OpenGL -framework AppKit \
		#-I /usr/local/include -L /usr/local/lib
LINKS =	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		

all: makelib $(NAME)

makelib:
	$(MAKE) --silent -C libft --no-print-directory
	$(MAKE) --silent -C mlx_linux --no-print-directory

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(LINKS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile $(H_PATH) | $(OBJ_PATH)  
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@	

clean :
	$(RM) -r $(OBJ_PATH)
	$(MAKE) --silent -C libft clean
	$(MAKE) --silent -C mlx_linux clean

fclean :
	$(RM) -r $(NAME) $(OBJ_PATH)
	$(MAKE) --silent -C libft fclean
	$(MAKE) --silent -C mlx_linux clean

re :
	make fclean --silent
	make all --silent
	$(MAKE) all --silent -C libft
	$(MAKE) all --silent -C mlx_linux

.PHONY: all clean fclean re
