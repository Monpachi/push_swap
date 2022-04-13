# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchan <vchan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 19:04:36 by vchan             #+#    #+#              #
#    Updated: 2022/03/04 17:01:32 by vchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################
MAKEFLAGS += --silent
#NAME_BONUS		=	checker
NAME		=	push_swap
RM			=	rm -f
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g3
AUTHOR = vchan@student.42.fr

################################################################################
#                          PROGRAM'S SRCS / OBJS                               #
################################################################################

SRCS		=	srcs/push_swap/algo_for3.c \
				srcs/push_swap/algo_for5.c \
				srcs/push_swap/algo_forplus_inf.c \
				srcs/push_swap/algo_forplus_sup.c \
				srcs/push_swap/bestmove.c \
				srcs/push_swap/check_sort.c \
				srcs/push_swap/checkandsort.c \
				srcs/push_swap/countmove_both.c \
				srcs/push_swap/countmove.c \
				srcs/push_swap/countrank.c \
				srcs/push_swap/free.c \
				srcs/push_swap/ft_push_swap_struct.c \
				srcs/push_swap/ft_split.c \
				srcs/push_swap/ft_utilities.c \
				srcs/push_swap/parsing.c \
				srcs/push_swap/push.c \
				srcs/push_swap/reverse_rotate.c \
				srcs/push_swap/rotate.c \
				srcs/push_swap/sort_param.c \
				srcs/push_swap/swap.c \
				srcs/gnl/get_next_line.c \
				srcs/gnl/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

#SRC_CHECKER	=	srcs/checker/main_checker.c

SRC_PS		=	srcs/push_swap/ft_push_swap.c

INCLUDE		=	-I ./include/

OBJS		=	$(SRCS:.c=.o)

#OBJ_CH		=	$(SRC_CHECKER:.c=.o)

OBJ_PS		=	$(SRC_PS:.c=.o)

%.o:			%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

################################################################################
#                                 Makefile rules                               #
################################################################################

define	progress_bar
	echo  -n "\r \e[1;32m 5%   [■■■ . . . . . . . . . . ]"
	sleep 0.2
	echo  -n "\r \e[1;32m 10%  [■■■■■■. . . . . . . . . ]"
	sleep 0.2
	echo  -n "\r \e[1;32m 28%  [■■■■■■■■■■. . . . . . . ]"
	sleep 0.2
	echo -n "\r \e[1;32m 42%  [■■■■■■■■■■■■. . . . . . ]"
	sleep 0.1
	echo -n "\r \e[1;32m 55%  [■■■■■■■■■■■■■■■■. . . . ]"
	sleep 0.1
	echo -n "\r \e[1;32m 69%  [■■■■■■■■■■■■■■■■■■■ . . ]"
	sleep 0.2
	echo -n "\r \e[1;32m 100% [■■■■■■■■■■■■■■■■■■■■■■■■]"
	echo " "
endef

all: compilation setup $(NAME)
compilation:
	echo "        "
	echo "\e[1;37m            ███████╗███████╗████████╗██╗  ██╗"
	sleep 0.1
	echo "\e[1;37m            ██╔════╝██╔════╝╚══██╔══╝██║  ██║"
	sleep 0.1
	echo "\e[1;37m            ███████╗█████╗     ██║   ███████║"
	sleep 0.1
	echo "\e[1;37m            ╚════██║██╔══╝     ██║   ██╔══██║"
	sleep 0.1
	echo "\e[1;37m            ███████║███████╗   ██║   ██║  ██║"
	sleep 0.1
	echo "\e[1;37m            ╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝"
	sleep 0.1
	echo "        "
	sleep 0.3
	echo "\033[1;33m ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗ check files ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗"
	echo "        "
	@$(call progress_bar)
	echo "        "
	echo "\033[1;33m ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗ compilation ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗"
	echo "        "
	sleep 1

setup:
	@$(call progress_bar)

$(NAME): $(OBJS) $(OBJ_PS)
	$(CC) $(CFLAGS) -o $@ $? || $(MAKE) $@
# $@ signifie ici  le target donc --> push_swap

#$(NAME_BONUS): $(OBJS) $(OBJ_PS)
#	$(CC) $(CFLAGS) -o $@ $? || $(MAKE) $@

clean:
	@$(RM) $(OBJS) $(OBJ_PS)
# @ on mute la ligne

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
