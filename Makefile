# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 17:02:00 by lauriago          #+#    #+#              #
#    Updated: 2024/04/26 17:29:13 by lauriago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SCR = test_run.c

OBJECTS = $(subst .c, .o, $(SCR))

FLAGS = -Wall -Wextra #-Werror

FT_L = -I libft -L libft

MLX_D = minilibx-linux
MLX_LIB = $(addprefix $(MLX_D)/, libmlx.a)
MLX_F = = -L $(MLX_D) -l mlx -L/usr/lib -I$(MLX_D) -lXext -lX11 -lz

#________________RULES__________#

$(NAME): $(OBJECTS)
	gcc $(SRC) -o $(NAME) $(FLAGS) $(MLX_F) $(FT_L)
