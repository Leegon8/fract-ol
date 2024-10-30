# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 12:49:15 by lauriago          #+#    #+#              #
#    Updated: 2024/06/02 11:09:11 by lauriago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME & HEADER#

NAME = libft.a

SRCS =  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isspace.c ft_isprint.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strncmp.c ft_strrchr.c ft_strtrim.c ft_tolower.c \
		ft_toupper.c ft_strnstr.c ft_putchar_fd.c ft_split.c ft_substr.c \
		ft_itoa.c ft_striteri.c ft_strmapi.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_strcmp.c ft_atol.c ft_printf.c \
		ft_putchar.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putunbr.c \
		
SRC_PATH = ./src/
OBJ_PATH = ./tmp/
OBJS = $(addprefix $(OBJ_PATH),$(SRCS:.c=.o))

#H_PATH = ../inc
#HEADERS = -I$(H_PATH)

#VARIABLES#

AR = ar rcs
RM = rm -f
CCFLAGS = -Wall -Wextra -Werror -g

#TARGETS#

#%.o: %.c $(HEADER)
#	cc $(CCFLAGS) -c $< -o $@

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile $(H_PATH)
	cc $(CCFLAGS) $(HEADERS) -c $< -o $@

#CLEAN#
clean: 
	$(RM) -rd $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME) $(OBJ_PATH)

#RE-MAKE#
re: 
	$(RM) $(NAME) $(OBJ_PATH)
	make all --silent

.PHONY: all clean fclean re

