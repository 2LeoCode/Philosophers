/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:11:17 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 02:52:43 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

/*
**	<ctype.h>
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isdigit(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_ispunct(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
/*
**
*/

/*
**	<string.h>
*/
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
char				*ft_stpcpy(char *dst, const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_stpncpy(char *dst, const char *src, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchrnul(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strcasecmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *m1, const void *m2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t n);
char				*ft_strcasestr(const char *haystack, const char *needle);
char				*ft_strncasestr(const char *haystack, const char *needle,
						size_t n);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memrchr(const void *s, int c, size_t n);
/*
**
*/

/*
**	<stdlib.h>
*/
long				ft_strtol(const char *nptr, char **endptr, int base);
long long			ft_strtoll(const char *nptr, char **endptr, int base);
unsigned long		ft_strtoul(const char *nptr, char **endptr, int base);
unsigned long long	ft_strtoull(const char *nptr, char **endptr, int base);
int					ft_atoi(const char *s);
long				ft_atol(const char *s);
long long			ft_atoll(const char *s);
void				*ft_malloc(size_t size);
void				ft_free(void *ptr);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_realloc(void *ptr, size_t size);
void				*ft_reallocarray(void *ptr, size_t nmemb, size_t size);
/*
**
*/

/*
**	<libft.h>
*/
long long			ft_abs(long long n);
void				ft_kek(void);
size_t				ft_strclen(const char *s, int stop);
char				*ft_stpccpy(char *dst, const char *src, int stop);
char				*ft_strccpy(char *dst, const char *src, int stop);
unsigned int		ft_atou(const char *s);
unsigned long		ft_atoul(const char *s);
unsigned long long	ft_atoull(const char *s);
char				*ft_strcchr(const char *s, int c, int stop);
char				*ft_strnchr(const char *s, size_t n, int c);
char				*ft_strrcchr(const char *s, int c, int stop);
char				*ft_strrnchr(const char *s, size_t n, int c);
char				*ft_strcstr(const char *haystack, const char *needle,
						int stop);
char				*ft_strccasestr(const char *haystack, const char *needle,
						int stop);
int					ft_strccmp(const char *s1, const char *s2, int stop);
int					ft_strccasecmp(const char *s1, const char *s2, int stop);
char				*ft_strcdup(const char *s, int stop);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s, const char *set);
char				**ft_split(const char *s, char c);
char				*ft_itoa(int n);
char				*ft_ltoa(long n);
char				*ft_lltoa(long long n);
char				*ft_ultoa(unsigned long n);
char				*ft_ulltoa(unsigned long long n);
char				*ft_strmap(const char *s, char (*f)(char));
void				ft_striter(char *s, void (*f)(char *));
int					ft_fprintc(int c, int fd);
int					ft_printc(int c);
int					ft_fprintstr(const char *s, int fd);
int					ft_printstr(const char *s);
int					ft_fprintln(const char *s, int fd);
int					ft_println(const char *s);
int					ft_printl(long n);
int					ft_printll(long long n);
int					ft_printul(unsigned long n);
int					ft_printull(unsigned long long n);
size_t				ft_blocksize(const void *m);
void				*ft_cmemset(void *dst, const void *src, size_t src_size,
						size_t n);
void				ft_swap(void *a, void *b, size_t size);

#endif
