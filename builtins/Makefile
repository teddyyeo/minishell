NAME = builtin_tester

SRC =	 env.c tester.c export.c utils.c pwd.c export_utils.c \
			unset.c

FLAG = -Werror -Wall -Wextra

CC = gcc
$(NAME): $(SRC)
	$(CC) $(FLAG) $(SRC) ../libft/libft.a -o builtin_tester

