/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 02:26:14 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:21:47 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_H
# define DATE_H
# define LUNDI                  1
# define MARDI                  2
# define MERCREDI               3
# define JEUDI                  4
# define VENDREDI               5
# define SAMEDI                 6
# define DIMANCHE               7
# define JANVIER                1
# define FEVRIER                2
# define MARS                   3
# define AVRIL                  4
# define MAI                    5
# define JUIN                   6
# define JUILLET                7
# define AOUT                   8
# define SEPTEMBRE              9
# define OCTOBRE                10
# define NOVEMBRE               11
# define DECEMBRE               12
# define YEAR                   date->year ==
# define D_AFTER(d)             date_after(date, 3, d, 3)
# define D_BEFORE(d)            date_before(date, 10, d, 2)
# define D_BEFORE0(d)           date_before(date, 9, d, 2)
# define BETWEEN(d, f)          D_AFTER(d) && D_BEFORE(f)
# define BETWEEN0(d, f)         D_AFTER(d) && D_BEFORE0(f)
# define D_TIME                 ft_date_modiftime
# define D_DATE                 ft_date_modifdate
# define D_TS                   ft_date_timestamp
# define D_DAY                  date->day
# define D_MONTH                date->month
# define D_HOUR                 date->hour
# define TIME(h, i, s, d, m, y) D_TS(D_DATE(D_TIME(NULL, s, i, h) ,d, m, y))

typedef struct  s_date
{
    int         seconde;
    int         minute;
    int         hour;
    int         day;
    int         month;
    int         year;
}               t_date;

t_date  *ft_date_convert(char *str);
t_date  *ft_date_modiftime(t_date *date, int sec, int minute, int hour);
t_date  *ft_date_modifdate(t_date *date, int day, int month, int year);
int     ft_date_summertime(t_date *date);
int     ft_date_diny(int year);
int     ft_date_dins(int day);
int     ft_date_hins(int hour);
int     ft_date_mins(int minute);
long    ft_date_mtos(int minute);
long    ft_date_htos(int hour);
long    ft_date_dtos(int day);
long    ft_date_timestamp(t_date *date);
long    ft_timestamp(char *str);

#endif
