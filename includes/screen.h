/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 05:02:43 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 07:41:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

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
    int             offset;
    int             size;
    t_case          *buffer;
}                   t_screen;

t_case              *ft_casescreate(void);
t_case              *ft_caseadd(t_case *cases, char *str, char *spec);
t_case              *ft_casendel(t_case *cases, int num);
t_case              *ft_casedel(t_case *cases, t_case *t_casedel);
void                ft_casedelete(t_case *cases);
void                ft_casesdel(t_case *cases);

t_screen            *ft_screeninit(void);
int                 ft_screenget_row(void);
int                 ft_screenget_col(void);
int                 ft_screenget_offset(void);
int                 ft_screenget_size(void);
t_case              *ft_screenget_buffer(void);
int                 ft_screenset_offset(int offset);
int                 ft_screenset_size(int size);
int                 ft_screenwrite_char(char c, char *spec);
int                 ft_screenwrite_str(char *str, char *spec);
int                 ft_screenprint(int fullscreen);

#endif
