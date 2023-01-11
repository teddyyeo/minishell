# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 02:45:44 by tayeo             #+#    #+#              #
#    Updated: 2022/10/15 21:52:25 by tayeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC=ft_atoi.c ft_isascii.c ft_memcpy.c ft_strlcat.c ft_strrchr.c \
ft_bzero.c ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_tolower.c \
ft_calloc.c ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c \
ft_isalnum.c ft_memchr.c ft_strchr.c ft_strncmp.c \
ft_isalpha.c ft_memcmp.c ft_strdup.c ft_strnstr.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c \
ft_printf.c format_str_parser.c put_uint.c put_hex.c basic_utils.c ft_putnbr.c \
get_next_line.c get_next_line_utils.c

OBJ = ${SRC:.c=.o}
FLAG = -Werror -Wall -Wextra -D BUFFER_SIZE=1

all: $(NAME)

$(NAME): $(OBJ)
	ar -r $@ $?
	ranlib $(NAME)

%.o: %.c
	gcc -c $(FLAG) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

