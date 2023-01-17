NAME = builtin_tester

SRC =		tester.c \
				env.c \
				pwd.c \
				cd.c \
				exit.c \
				echo.c \
				export.c export_utils.c \
				unset.c \
				utils.c utils2.c

FLAG = -Werror -Wall -Wextra

CC = gcc
$(NAME): $(SRC)
	$(CC) $(FLAG) $(SRC) ../libft/libft.a -o builtin_tester

leak:
	leaks `ps | grep './builtin_tester' | head -n 1 | awk '{print $$1}'`
