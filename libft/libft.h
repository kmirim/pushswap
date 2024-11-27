/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:59:27 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/05/02 22:30:47 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

int		ft_atoi(const char *nptr);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmeb, size_t size);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

int		ft_printf(const char *format, ...);

char	*ft_itoa(int n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memset(void *s, int c, size_t n);

void	ft_putchar_fd(char c, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int c, int fd);

char	*ft_strnstr(const char *big, const char *little, size_t len);

void	ft_putstr_fd(char *s, int fd);

char	**ft_split(const char *s, char c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

char	*ft_strdup(const char *s);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlcat(char *dst, const char *scr, size_t dssize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s1, char const *set);

int		ft_tolower(int c);

int		ft_toupper(int c);

t_list	*ft_lstnew(int content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

char	*ft_putnbr_base(long long n, int base, char *digits);

int		ft_printf(const char *format, ...);

int		ft_putnbr_u(unsigned int n);

int		ft_puthex(unsigned long long n, const char fmt);

int		ft_printf_pointer(unsigned long long n);

int		ft_putchar(char c);

int		ft_putnbr(int n);

int		ft_putstr(char *s);

char	*ft_strjoin2(char *s1, char *s2);

char	*get_next_line(int fd);

int		finish_line(t_list *stock);

t_list	*ft_last_node(t_list *stock);

void	ft_read(int fd, t_list **stock);

void	ft_stock(t_list **stock, char *buf, int bytes);

void	ft_line(t_list *stock, char **line);

void	ft_malloc_line(char **line, t_list *stock);

void	ft_clean(t_list **stock);

char	*ft_substr2(char *s, unsigned int start, size_t len, char c);

size_t	ft_strlen2(char *s);

int		nl_(char *s);

void	free_stock(t_list *stock);

#endif
