# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 16:23:21 by stross            #+#    #+#              #
#    Updated: 2019/11/22 23:02:15 by stross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = float.c libft_f2.c libft_f6.c print_f2.c print_o2.c print_x2.c printf_u2.c utils3.c ft_printf.c libft_f3.c libft_f7.c print_l.c print_p.c printf_d.c printf_u3.c libft_f4.c print_c.c print_l2.c print_s.c printf_d2.c utils.c libft_f1.c libft_f5.c print_f.c print_o.c print_x.c printf_u.c utils2.c colors.c

OBJ = $(SRC:.c=.o)

SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))


CFLAGS = -c -Wall -Wextra -Werror

NAME = libftprintf.a

.PHONY: all clean fclean re
	.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		@/bin/mkdir -p $(OBJDIR)
			@gcc $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
		@ar rcs $@ $^
			@ranlib $@
			@echo "\033[32m$(NAME) OK ! \033[0m"

clean:
		@/bin/rm -rf $(OBJDIR)
		@echo "\033[33mObject deleted\033[0m"

fclean: clean
		@/bin/rm -f $(NAME)
		@echo "\033[33mExec deleted\033[0m"

re: fclean all
