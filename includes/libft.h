/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:09:36 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/11 13:56:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# define BUFF_SIZE 		100

typedef unsigned char	t_char;
typedef unsigned char	*t_pchar;

typedef struct 			s_tab
{
	int					**tab;
	int					col;
	int					line;
}						t_tab;

typedef struct  s_point
{
    int         x;
    int         y;
    int         z;
    int         cx;
    int         cy;
    int         cz;
}               t_point;

void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putnbr_endl(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
char	**ft_strsplit(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_ctos(char c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(char *str);
size_t	ft_nbrlen(int nbr);
char	*ft_strdup(char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strcat(char *s1, char const *s2);
char	*ft_strncat(char *s1, char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strcchr(char *source, char *search);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcasestr(const char *s1, const char *s2);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strcasestr(const char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmjoin(char const *s1, char const *s2, char const *s3);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	**ft_str_split(char const *s, char c);
int		ft_strnrpl(char **source, char *search, char *remplace, int n);
char	*ft_strmore(char *str, size_t n);
int		ft_readfile(int fd, char **str);
int		ft_gnl(int const fd, char **line);
t_tab	*ft_tabnew(int line, int col);
void	ft_straddchar(char **str, char c);
int     ft_tabmin(t_tab *tab);
int     ft_tabmax(t_tab *tab);
int     ft_puttab(t_tab *tab);
void    ft_tabclear(t_tab **tab);
t_tab   *ft_tabdel(t_tab **tab);
t_point	*ft_pointnew(int x, int y, int z);
t_point	*ft_pointcpy(t_point *p);
void	ft_pointdel(t_point *point);
void	ft_tabup(t_tab *tab, int up);
int		ft_power(int nbr, int power);
int     ft_neg(int nbr);
int     ft_dectobin(int dec);
int		ft_bintodec(int bin);
int     ft_rgb(int red, int green, int blue);
int     ft_abs(int n);

#endif
