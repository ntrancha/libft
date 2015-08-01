/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 05:02:43 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/01 02:41:02 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H
# define TAB		4
# define SPACE		" "
# define C_NULL    "\033[0m"
# define C_BLACK    "\033[30m"
# define C_RED      "\033[31m"
# define C_GREEN    "\033[32m"
# define C_YELLOW   "\033[33m"
# define C_BLUE     "\033[34m"
# define C_MAGENTA  "\033[35m"
# define C_CYAN     "\033[36m"
# define C_GRAY     "\033[37m"
# define C_WHITE    "\033[39m"
# define B_NULL    "\033[49m"
# define B_BLACK    "\033[40m"
# define B_RED      "\033[41m"
# define B_GREEN    "\033[42m"
# define B_YELLOW   "\033[43m"
# define B_BLUE     "\033[44m"
# define B_MAGENTA  "\033[45m"
# define B_CYAN     "\033[46m"
# define B_GRAY     "\033[47m"
# define B_WHITE    "\033[39m"


typedef struct      s_case
{
    char            *str;
    char            *spec;
    struct s_case   *next;
}                   t_case;

typedef struct      s_screen
{
    int             row;
    int             col;
    int             line;               // Line du curseur dans le buffer
    int             offset;             // Position du curseur dans le buffer
    int             cursor;             // Position du curseur dans l'original
    int             size;               // Taile de la chaine originale
    t_case          *buffer;            // Chaine traitee
    t_case          *original;          // Chaine a afficher
}                   t_screen;

t_case              *ft_casescreate(void);
t_case              *ft_caseadd(t_case *cases, char *str, char *spec);
int                 ft_caseset(t_case *cases, int num, char *str, char *spec);
t_case              *ft_casendel(t_case *cases, int num);
t_case              *ft_casedel(t_case *cases, t_case *t_casedel);
t_case              *ft_casedelend(t_case *cases);
void                ft_casedelete(t_case *cases);
void                ft_casesdel(t_case *cases);

t_screen            *ft_screeninit(void);
int                 ft_screenget_row(void);
int                 ft_screenget_col(void);
int                 ft_screenget_offset(void);
int                 ft_screenget_cursor(void);
int                 ft_screenget_size(void);
t_case              *ft_screenget_buffer(void);
t_case              *ft_screenget_original(void);
int                 ft_screenset_offset(int offset);
int                 ft_screenset_cursor(int offset);
int                 ft_screenset_lcursor(int col, int row);
int                 ft_screenset_size(int size);
int                 ft_screenwrite_char(char c, char *spec);
int                 ft_screenwrite_str(char *str, char *spec);
void                ft_screenprint(void);
void                ft_screenbuffering(void);
void                ft_screenfree(void);
void                ft_screenclear(void);
void                ft_screenclean(void);
void                ft_screenreset(void);
void                ft_screenfull(char c, char *spec);
int                 ft_screenis_full(void);

#endif
