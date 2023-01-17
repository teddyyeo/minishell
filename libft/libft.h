/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:32:48 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 22:44:18 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include<stdlib.h>
# include <stdarg.h>
# include<unistd.h>

long long		ft_atoi(const char *s);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *d, const char *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);

char	**ft_split(char const *str, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);

int		ft_printf(const char *format, ...);
int		format_str_parser(va_list arg_ptr, char format);
int		put_uint(unsigned int num);
int		put_hex_int(int num, char c);
int		put_hex_addr(void *addr);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);

char	*get_next_line(int fd);
char	*saver(char **safe);
size_t	gnl_ft_strlen(const char *s);
char	*gnl_ft_strjoin(char const *s1, char const *s2, int flag);
void	*gnl_ft_memmove(void *dest, const void *src, size_t n);
char	*gnl_ft_strchr(const char *s, int c);
char	*end_of_file(char **safe);
#endif
