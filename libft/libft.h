/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:30:27 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/05 20:09:15 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;	
}	t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int d);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int ch);
char			*ft_strrchr(const char *src, int ch);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, unsigned long n);
char			*ft_strnstr(const char *haystack, const char *needle,
					unsigned long len);
int				ft_atoi(char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
//int				ft_lstsize(t_list *lst);
//t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
//get_next_line
size_t			str_length(const char *str);
char			*strjoin_content_buf(char *s1, char *s2);
char			*strchr_locate_nl(const char *str, int nl);
char			*read_fd(int fd, char *content);
char			*current_line(char *content);
char			*clear_previous_line(char *content);
char			*get_next_line(int fd);
#endif
