# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jijeong <jijeong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 14:40:05 by jijeong           #+#    #+#              #
#    Updated: 2022/11/26 17:51:55 by jijeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
AR = ar
ARFLAG = -rcs
CC = cc
CFLAG = -Wall -Wextra -Werror -fsanitize=address
RM = rm
RMFLAG = -fr

SRCS =	minishell.c			\
		ms_error.c			\
		ms_parse_cmdline.c
SRCS_B =
OBJS = $(SRCS:%.c=%.o)
OBJS_B = $(SRCS_B:%.c=%.o)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAG) $^ -L libft -l ft -l readline -o $@

$(NAME_B) : $(OBJS_B)
	$(CC) $(CFLAG) $^ -o $@

%.o : %.c
	$(CC) $(CFLAG) -c $^ -o $@

all : $(NAME)

bonus : $(NAME_B)

clean :
	make -C libft clean
	$(RM) $(RMFLAG) $(OBJS) $(OBJS_B)

fclean :
	make clean
	make -C libft fclean
	$(RM) $(RMFLAG) $(NAME) $(NAME_B)

re :
	make fclean
	make all

.PHONY: all bonus clean fclean re
