/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:12:56 by ciusca            #+#    #+#             */
/*   Updated: 2024/06/19 15:49:50 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* string functions */
long long		ft_atoi(const char *str);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);

/* int functions */
void	ft_putnbr_fd(int nb, int fd);

/* char functions */
void	ft_putchar_fd(char c, int fd);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* non standard functins */
char	*ft_itoa(int n);
int		n_len(long n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
int		count_words(char *str);

/* matrix functions */
char	**ft_split(char const *s, char const c);
int		matrix_len(char **mat);
char	**ft_matrix_dup(char **matrix);
void	free_matrix(char **mat);

/* memory functions */
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

/* list functions */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* printf functions */
int		pf_toupper(int c, int change);
int		pf_itoa(long cifra);
int		ft_printf_uns(unsigned int cifra);
int		ft_putchar(char c);
int		ft_printf(const char *str, ...);
int		pf_putstr(char *s);
int		hexa_converter(unsigned int n, int change);
int		printf_hex(unsigned long long ptr);

/* get_next_line */
char	*get_next_line(int fd);

#endif
