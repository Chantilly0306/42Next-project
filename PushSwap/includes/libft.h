/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:42:51 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/25 00:49:27 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_swap
{
	char *a;
	char *b;
	char tmp;
	size_t i;
}	t_swap;

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

/* _STDLIB.H_ */

int ft_atoi(const char *nptr);
long ft_atol(const char *str);
void *ft_calloc(size_t nmemb, size_t siz);
char *ft_itoa(int n);
void *ft_realloc(void **ptr, size_t old, size_t new);


/* _CTYPE.H_ */

int ft_isalpha(char c);
int ft_isascii(int c);
int ft_isdigit(char c);
int ft_is_lowercase(char c);
int ft_is_uppercase(char c);
int ft_is_whitespace(char c);
int ft_isalnum(char c);
int ft_isprint(int c);
char ft_tolower(char c);
char ft_toupper(char c);


/* _STRING.H_ */

void ft_bzero(void *s, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memmove(void *dst, const void *src, size_t n);
void *ft_memset(void *s, int c, size_t n);
char **ft_split(char const *s, char c);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *src);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlcat(char *dst, const char *src, size_t siz);
size_t ft_strlcpy(char *dst, const char *src, size_t siz);
size_t ft_strlen(const char *str);
int	ft_strcmp(const char *s1, const char *s2);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr(const char *big, const char *little, size_t len);
char *ft_strrchr(const char *s, int c);
char *ft_strtrim(char const *s1, char const *set);
char *ft_substr(char const *s, unsigned int start, size_t len);
void ft_swap(void *a, void *b, size_t size);

/* _STDIO.H_ */

void ft_putchar_fd(char c, int fd);
void ft_putendl_fd(char *str, int fd);
void ft_putstr_fd(char *str, int fd);


/* _FT OF FT_ */

void ft_striteri(char *s, void (*f)(unsigned int, char *));
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));


/* _LINKED LIST_ */

void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void(*f)(void *));
t_list *ft_lstlast(t_list *lst);
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list *ft_lstnew(void *content);
int ft_lstsize(t_list *lst);


#endif