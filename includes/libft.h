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
# include "macros.h"
# include "math.h"

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;
typedef signed char		t_schar;
typedef signed int		t_sint;
typedef long long		t_ll;

typedef struct			s_strnrpl
{
	char				**str;
	char				*str2;
	char				*str3;
	int					*start;
	int					*count;
}						t_strnrpl;

typedef struct			s_tab
{
	int					**tab;
	int					col;
	int					line;
}						t_tab;

typedef struct			s_lst
{
	void				*content;
	size_t				content_size;
	struct s_lst		*next;
}						t_lst;

typedef struct          s_node
{
	void				*content;
	struct s_node		*next;
	struct s_node		*previous;
}						t_node;

typedef struct          s_list
{
    t_node				*start;
    t_node				*end;
	int					size;
}						t_list;

char	*ft_itoa(int n);
char	*ft_ltoa(long n);
char	*ft_ftoa(float n);
char	*ft_dtoa(double n);
char	*ft_ctos(char c);
char	*ft_listtostr(t_list *list);
char	*ft_listtostrd(t_list *list, char *del);
int		ft_atoi(const char *str);
int		ft_ltoi(long n);
int		ft_ftoi(float n);
int		ft_dtoi(double n);
int		ft_dectobin(int dec);
int		ft_bintodec(int bin);
long	ft_atol(const char *str);
long	ft_itol(int n);
long	ft_dtol(double n);
long	ft_ftol(float n);
t_ll	ft_itoll(int n);
t_ll	ft_ltoll(long n);
t_ll	ft_dtoll(double n);
t_ll	ft_ftoll(float n);
t_ll	ft_atoll(const char *str);
float	ft_atof(const char *str);
float	ft_itof(int n);
float	ft_ltof(long n);
float	ft_dtof(double n);
float	ft_fround(float n, int p);
double	ft_atod(const char *str);
double	ft_itod(int n);
double	ft_ltod(long n);
double	ft_ftod(float n);

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_istolower(int c);
int		ft_istoupper(int c);
int		ft_isspace(char c);
int		ft_is_prime(int nbr);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_listcontent(t_list *list, t_node *node);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_memdel(void **ap);
void	ft_strdel(char **as);
void	ft_tabstrdel(char **str);
void	ft_lstdel(t_lst **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_lst **alst, void (*del)(void *, size_t));
void	ft_listdel(t_list *list, void (del)(void **));
void	ft_listdelnode(t_list *list, t_node *node, void (del)(void **));
t_node	*ft_listdelnext(t_list *list, t_node *node, void (del)(void **));
t_tab	*ft_tabdel(t_tab **tab);

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	ft_tabclear(t_tab **tab);

void	*ft_memalloc(size_t size);
void	ft_lstadd(t_lst **alst, t_lst *new);
char	*ft_strnew(size_t size);
t_tab	*ft_tabnew(int line, int col);
t_lst	*ft_lstnew(void const *content, size_t content_size);
t_list	*ft_listadd(t_list *list, void *content);
t_list	*ft_listaddfirst(t_list *list, void *content);
t_list	*ft_listaddafter(t_list *list, t_node *prev, void *content);
t_list	*ft_listcreate(void);

void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_lstiter(t_lst *lst, void (*f)(t_lst *elem));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_lst	*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem));

int		ft_strcchr(char *source, char *search);
int		ft_match(char const *str, char const *match);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strcasestr(const char *s1, const char *s2);
void	*ft_memchr(const void *s, int c, size_t n);

char	*ft_strdup(const char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strmore(char *str, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
t_tab	*ft_tabdup(t_tab *tab);

int		ft_nbrcat(int nbr, int nbr2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strcat(char *s1, char const *s2);
char	*ft_strncat(char *s1, char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmjoin(char const *s1, char const *s2, char const *s3);
void	ft_straddchar(char **str, char c);
void	ft_strfusion(char **dst, char **src);
void	ft_strfusiondel(char **dst, char **src);

size_t	ft_strlen(const char *str);
size_t	ft_nbrlen(int nbr);
size_t	ft_listlen(t_list *list);
size_t	ft_liststrlen(t_list *list);
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
void    *ft_ralloc(void *ptr, size_t size_of, size_t new_size);
void	ft_listswap(t_list *list, t_node *node, t_node *node2);

int		ft_gnl(int const fd, char **line);
int     ft_gnl_list(int const fd, char **line);
int		ft_readfile(int const fd, char **str);
int		ft_readfilelist(int const fd, t_list *list);
int		ft_catfile_list(const int fd);
int		ft_catfile(const int fd);

int		ft_rgb(int red, int green, int blue);

char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

char	*ft_strrvs(char *str);
t_list	*ft_listreverse(t_list *list);

int		ft_tabmin(t_tab *tab);
int		ft_tabmax(t_tab *tab);
void	ft_tabup(t_tab *tab, int up);

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);

void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putnbr_endl(int n);
void	ft_putfloat(float n);
void	ft_putlong(long n);
void	ft_putdouble(double n);
void	ft_listputstr(t_list *list, void (put)(char const *));
int		ft_puttab(t_tab *tab);

#endif
