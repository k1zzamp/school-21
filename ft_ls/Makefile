# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 16:04:45 by stross            #+#    #+#              #
#    Updated: 2019/11/05 17:30:46 by stross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:
.SUFFIXES: .c .o .h
.PHONY: all clean fclean re

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = libft
#VPATH = sources
SRC = ./sources/main.c ./sources/errors.c
OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L $(LIBFT_PATH) -lft

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH)

%.o: %.c ft_ls.h
	$(CC) $(CFLAGS) -c $< -I $(LIBFT_PATH)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all
