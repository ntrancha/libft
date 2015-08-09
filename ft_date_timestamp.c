/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_timestamp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:46:21 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/09 22:55:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>
#define YEAR    date->year

int			days_since_year(t_date *date)
{
	int		ret;
	int		year;

	ret = 0;
	year = YEAR;
	while (year > 1970)
		ret += ft_date_diny(--year);
	return (ret);
}

int			days_since_month(t_date *date)
{
	int		month;
	int		ret;

	month = date->month;
	ret = 0;
	while (--month > 0)
		if (month == 11 || month == 9 || month == 6 || month == 4)
			ret += 30; 
		else if (month == 2)
        {
			ret += (ft_date_diny(YEAR) == 365) ? 28 : 29;
        }
		else
			ret += 31; 
	return (ret);
}

int     date_after(t_date *date, int month, int day, int hour)
{
    if (date->month > month)
        return (1);
    if (date->month == month && date->day > day)
        return (1);
    if (date->month == month && date->day == day && date->hour >= hour)
        return (1);
    return (0);
}

int     date_before(t_date *date, int month, int day, int hour)
{
    if (date->month < month)
        return (1);
    if (date->month == month && date->day < day)
        return (1);
    if (date->month == month && date->day == day && date->hour < hour)
        return (1);
    return (0);
}

int     date_summertime(t_date *date)
{
    if (YEAR == 1980)
        return (date_after(date, 4, 6, 3) && date_before(date, 9, 99, 99));
    if (YEAR == 1982 || YEAR == 1993)
        return (date_after(date, 3, 99, 99) && date_before(date, 9, 26, 2));
    if (YEAR == 1983 || YEAR == 1988 || YEAR == 1994)
        return (date_after(date, 3, 99, 99) && date_before(date, 9, 25, 2));
    if (YEAR == 1984 || YEAR == 1990)
        return (date_after(date, 3, 25, 3) && date_before(date, 9, 99, 99));
    if (YEAR == 1989 || YEAR == 1995)
        return (date_after(date, 3, 26, 3) && date_before(date, 9, 24, 2));
    if (YEAR == 1996 || YEAR == 1999 || YEAR == 2002 || YEAR == 2004 || YEAR == 2016 || YEAR == 2027)
        return (date_after(date, 3, 99, 99) && date_before(date, 10, 99, 99));
    if (YEAR == 1997 || YEAR == 2003 || YEAR == 2008 || YEAR == 2014 || YEAR == 2025 || YEAR == 2031)
        return (date_after(date, 3, 99, 99) && date_before(date, 10, 26, 2));
    if (YEAR == 1998 || YEAR == 2009 || YEAR == 2015 || YEAR == 2020 || YEAR == 2026)
        return (date_after(date, 3, 99, 99) && date_before(date, 10, 25, 2));
    if (YEAR == 2000 || YEAR == 2006 || YEAR == 2017 || YEAR == 2023 || YEAR == 2028)
        return (date_after(date, 3, 26, 3) && date_before(date, 10, 99, 99));
    if (YEAR == 2001 || YEAR == 2007 || YEAR == 2012 || YEAR == 2018 || YEAR == 2029)
        return (date_after(date, 3, 25, 3) && date_before(date, 10, 99, 99));
    if (YEAR > 1980 && YEAR < 2005)
        if (date->month >= 4 && date->month < 10)
            return (1);  
    if (YEAR >= 2005)
        return (date_after(date, 3, 99, 99) && date_before(date, 10, 27, 3));
    return (0);
}

int			ft_date_timestamp(t_date *date)
{
	int		days;
	int		ret;
    int     summer;

	days = date->day - 1;
    summer = date_summertime(date);
	days += days_since_year(date) + days_since_month(date);
	ret = date->seconde + ft_date_mtos(date->minute);
	ret += ft_date_htos(date->hour - 1) + ft_date_dtos(days);
    if (summer == 1)
        ret -= 60 * 60;
    free(date);
	return (ret);
}

int main(int argc, char **argv)
{
    t_date  *date;

    if (argc == 2)
    {
        date = ft_date_convert(argv[1]);
        ft_putnbr_endl(ft_date_timestamp(date));
    }
	return (1);
}
