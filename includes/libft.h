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

# define BUFF_SIZE		1
# define TRUE			1
# define FALSE			0
# define STDIN			0
# define STDOUT			1
# define STDERR			2
# define MAX_DTOA		10000000000000
# define MAX_FTOA		10000000
# define PI				3.141593
# define PHI			1.618032
# define SQUARE2		1.414213
# define EXIT_SUCCES	1
# define EXIT_NULL		0
# define EXIT_FAIL		-1
# define EXIT_ERROR		-2
# define PUT_ENDL		ft_putchar('\n')
# define POWER			ft_power
# define FACTO			ft_facto
# define SQUARE			ft_sqrt
# define ROOT			ft_rsqrt
# define SIN			ft_sin
# define COS			ft_cos
# define TAN			ft_tan
# define ABS			ft_abs
# define NEG			ft_neg

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;
typedef signed char		t_schar;
typedef signed int		t_sint;
typedef long long		t_ll;

typedef struct 			s_strnrpl
{
	char				**str;
	char				*str2;
	char				*str3;
	int					*start;
	int					*count;
}						t_strnrpl;

typedef struct 			s_tab
{
	int					**tab;
	int					col;
	int					line;
}						t_tab;

typedef struct			s_dlist
{
	void				*content;
	size_t				content_size;
	struct s_dlist		*next;
	struct s_dlist		*previous;
}						t_dlist;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

int		ft_abs(int n);
int		ft_find_next_prime(int nb);
int		ft_neg(int nbr);
int		ft_power(int nbr, int power);
int		ft_sqrt(int nbr);
int		ft_facto(int nb);
long	ft_abs_long(long n);
long	ft_neg_long(long nbr);
t_ll	ft_abs_longlong(long long n);
float	ft_abs_float(float n);
float	ft_neg_float(float nbr);
float	ft_rsqrt(float nb);
float	ft_cos(float angle);
float	ft_sin(float angle);
float	ft_tan(float angle);
double	ft_abs_double(double n);
double	ft_neg_double(int nbr);

char	*ft_itoa(int n);
char	*ft_ltoa(long n);
char	*ft_ftoa(float n);
char	*ft_dtoa(double n);
char	*ft_ctos(char c);
int		ft_atoi(const char *str);
int		ft_ltoi(long n);
int		ft_ftoi(float n);
int		ft_dtoi(double n);
int		ft_dectobin(int dec);
int		ft_bintodec(int bin);
long	ft_atol(const char *str);
long	ft_itol(int n);
float	ft_atof(const char *str);
float	ft_itof(int n);
float	ft_fround(float n, int p);
double	ft_atod(const char *str);
double	ft_itod(int n);

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_is_prime(int nbr);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_memdel(void **ap);
void	ft_strdel(char **as);
void	ft_tabstrdel(char **str);
t_tab	*ft_tabdel(t_tab **tab);

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	ft_tabclear(t_tab **tab);

void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);
t_tab	*ft_tabnew(int line, int col);

void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_strcchr(char *source, char *search);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strcasestr(const char *s1, const char *s2);
void	*ft_memchr(const void *s, int c, size_t n);

char	*ft_strdup(char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strmore(char *str, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

int		ft_nbrcat(int nbr, int nbr2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strcat(char *s1, char const *s2);
char	*ft_strncat(char *s1, char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmjoin(char const *s1, char const *s2, char const *s3);
void	ft_straddchar(char **str, char c);
void	ft_strfusion(char **dst, char **src);

size_t	ft_strlen(char *str);
size_t	ft_nbrlen(int nbr);
size_t	ft_floatlenfloat(float n);
size_t	ft_floatlen(float n);
size_t	ft_longlen(long nbr);
size_t	ft_doublelen(double n);
size_t	ft_doublelendouble(double n);
int		ft_cinstr(char *str, char c);

char	*ft_strtrim(char const *s);
char	*ft_strcleanback(char *str, char c);
char	*ft_strcleanfront(char *str, char c);

void	ft_strclr(char *s);
void	ft_strtoupper(char *str);
void	ft_strtolower(char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strnrpl(char **source, char *search, char *remplace, int n);

char	*ft_strralloc(char **str, int len);
void	*ft_memmove(void *dst, const void *src, size_t len);

int		ft_gnl(int const fd, char **line);
int		ft_readfile(int fd, char **str);

int		ft_rgb(int red, int green, int blue);

char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

char	*ft_strrvs(char *str);

int		ft_tabmin(t_tab *tab);
int		ft_tabmax(t_tab *tab);
void	ft_tabup(t_tab *tab, int up);

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putnbr_endl(int n);
void	ft_putfloat(float n);
void	ft_putlong(long n);
void	ft_putdouble(double n);
int		ft_puttab(t_tab *tab);

void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t content_size);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
