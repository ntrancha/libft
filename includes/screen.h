/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 05:02:43 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/01 01:02:00 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H
# define TAB		4
# define SPACE		" "

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
int                 ft_screenget_size(void);
t_case              *ft_screenget_buffer(void);
t_case              *ft_screenget_original(void);
int                 ft_screenset_offset(int offset);
int                 ft_screenset_cursor(int offset);
int                 ft_screenset_size(int size);
int                 ft_screenwrite_char(char c, char *spec);
int                 ft_screenwrite_str(char *str, char *spec);
void                ft_screenprint(void);
void                ft_screenbuffering(void);
void                ft_screenfree(void);

#endif
