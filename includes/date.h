/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 02:26:14 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/07 14:23:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_H
# define DATE_H
# define LUNDI      1
# define MARDI      2
# define MERCREDI   3
# define JEUDI      4
# define VENDREDI   5
# define SAMEDI     6
# define DIMANCHE   7
# define JANVIER    1
# define FEVRIER    2
# define MARS       3
# define AVRIL      4
# define MAI        5
# define JUIN       6
# define JUILLET    7
# define AOUT       8
# define SEPTEMBRE  9
# define OCTOBRE    10
# define NOVEMBRE   11
# define DECEMBRE   12

typedef struct  s_date
{
    int         seconde;
    int         minute;
    int         hour;
    int         day;
    int         month;
    int         year;
}               t_date;

int     ft_date_mins(int minute);
int     ft_date_hins(int hour);
int     ft_date_dins(int day);
t_date  *ft_date_modiftime(t_date *date, int sec, int minute, int hour);
t_date  *ft_date_modifdate(t_date *date, int day, int month, int year);
int     ft_date_timestamp(t_date *date);

#endif
