# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 02:06:32 by ccouliba          #+#    #+#              #
#    Updated: 2021/09/22 19:30:15 by ccouliba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = @gcc

CFLAGS =  -Wall -Wextra -Werror #-g3 -fsanitize=address

SRCS =	libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c \
	libft/ft_lstdelone.c libft/ft_lstlast.c libft/ft_lstnew.c \
	libft/ft_lstsize.c libft/ft_atoll.c libft/ft_strlen.c \
	srcs/error_handling/check_stack.c \
	srcs/error_handling/parsing_arg.c \
	srcs/error_handling/init_stack.c \
	srcs/operations/swap.c \
	srcs/operations/rotate.c \
	srcs/operations/rev_rotate.c \
	srcs/operations/push.c \
	srcs/algos/push_swap.c \
	srcs/algos/mini_sort.c \
	srcs/algos/medium_sort.c \
	srcs/algos/big_sort.c \
	srcs/algos/ps_utils.c \

_GREY=	$'\033[1;30m
_RED=	$'\033[1;31m
_GREEN=	$'\033[1;32m
_YELLOW=$'\033[1;33m
_BLUE=	$'\033[1;34m
_PURPLE=$'\033[1;35m
_CYAN=	$'\033[1;36m
_WHITE=	$'\033[1;37m

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(_YELLOW)[Compilation on going ...]"
		@sleep 1
		@echo "$(_GREEN)[Compilation finished]"
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "$(_CYAN)[Executable created]"
		@echo [Name : push_swap]

%o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "$(_RED)[All .o removed]"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_RED)[Executable removed]"

re: fclean all

.PHONY : all bonus clean fclean re
