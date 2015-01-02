/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:42:48 by ntrancha          #+#    #+#             */
/*   Updated: 2015/01/02 17:42:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H
# include "libft.h"

typedef struct          s_strnrpl
{
    char                **str;
    char                *str2;
    char                *str3;
    int                 *start;
    int                 *count;
}                       t_strnrpl;

int     ft_strequ(char const *s1, char const *s2);
int     ft_strnequ(char const *s1, char const *s2, size_t n);
int     ft_strcmp(const char *s1, const char *s2);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    ft_strdel(char **as);
void    ft_tabstrdel(char **str);
char    *ft_strnew(size_t size);
void    ft_striter(char *s, void (*f)(char *));
void    ft_striteri(char *s, void (*f)(unsigned int, char *));
char    *ft_strmap(char const *s, char (*f)(char));
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
int     ft_strcchr(char *source, char *search);
int     ft_match(char const *str, char const *match);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
char    *ft_strstr(const char *s1, const char *s2);
char    *ft_strnstr(const char *s1, const char *s2, size_t n);
char    *ft_strcasestr(const char *s1, const char *s2);
char    *ft_strdup(const char *str);
char    *ft_strcpy(char *dst, const char *src);
char    *ft_strncpy(char *dst, const char *src, size_t n);
char    *ft_strmore(char *str, size_t n);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
char    *ft_strcat(char *s1, char const *s2);
char    *ft_strncat(char *s1, char *s2, size_t n);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strmjoin(char const *s1, char const *s2, char const *s3);
void    ft_straddchar(char **str, char c);
void    ft_strfusion(char **dst, char **src);
void    ft_strfusiondel(char **dst, char **src);
char    *ft_strtrim(char const *s);
char    *ft_strcleanback(char *str, char c);
char    *ft_strcleanfront(char *str, char c);
void    ft_strclr(char *s);
void    ft_strtoupper(char *str);
void    ft_strtolower(char *str);
int     ft_toupper(int c);
int     ft_tolower(int c);
int     ft_strnrpl(char **source, char *search, char *remplace, int n);
char    *ft_strralloc(char **str, int len);
char    **ft_strsplit(char const *s, char c);
char    *ft_strsub(char const *s, unsigned int start, size_t len);
char    *ft_strrvs(char *str);

#endif
