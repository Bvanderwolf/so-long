/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:10:21 by bvan-der          #+#    #+#             */
/*   Updated: 2022/12/28 13:38:38 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/* Represents a node in a linked list. */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* PART ONE */

/*Returns whether given integer (converted to a char) is a digit or a letter.*/
int		ft_isalnum(int c);
/*Returns whether given integer (converted to a char) is a letter.*/
int		ft_isalpha(int c);
/*Returns whether given integer (converted to a char) is an ascii char. */
int		ft_isascii(int c);
/*Returns whether given integer (converted to a char) is a digit.*/
int		ft_isdigit(int c);
/*Returns whether given integer (converted to a char) is printable.*/
int		ft_isprint(int c);
/*Returns the pointer to the first character 'c' found in string 's'.*/
char	*ft_strchr(const char *s, int c);
/*Copies over characters from 'src' to 'dst' based on given destination size.*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*Appends characters from 'src' to 'dst' based on given destination size.*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/*Returns the amount of characters in string 's' based on null termination.*/
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);

/* PART TWO */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* BONUS FUNCTIONS */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ADDITIONAL FUNCTIONS */

/*Returns the amount of characters in number 'n' including the '-'.*/
int		ft_numlen(int n, int base);
/*Returns the amount of characters in string 's' based on null terminator 't'.*/
size_t	ft_strtlen(const char *s, char t);
/*Returns the index of the first character 'c' found in string 's'.*/
ssize_t	ft_strchri(const char *s, int c);
/*Returns the index of the last character 'c' found in string 's'.*/
ssize_t	ft_strrchri(const char *s, int c);

#endif