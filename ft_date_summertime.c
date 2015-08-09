/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_summertime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 01:41:11 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/10 01:56:56 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int  date_after(t_date *date, int month, int day, int hour)
{
    if (date->month > month)
        return (1);
    if (date->month == month && date->day > day)
        return (1);
    if (date->month == month && date->day == day && date->hour >= hour)
        return (1);
    return (0);
}

static int  date_before(t_date *date, int month, int day, int hour)
{
    if (date->month < month)
        return (1);
    if (date->month == month && date->day < day)
        return (1);
    if (date->month == month && date->day == day && date->hour < hour)
        return (1);
    return (0);
}

static int  date_summertime3(t_date *date)
{
    if (YEAR 2029 || YEAR 2030)
        return (date_after(date, 3, 31, 3) && date_before(date, 10, 27, 2));
    if (YEAR 2031 || YEAR 2036)
        return (date_after(date, 3, 30, 3) && date_before(date, 10, 26, 2));
    if (YEAR 2037)
        return (date_after(date, 3, 29, 3) && date_before(date, 10, 25, 2));
    if (YEAR 2032)
        return (date_after(date, 3, 28, 3) && date_before(date, 10, 31, 2));
    if (YEAR 2034)
        return (date_after(date, 3, 26, 3) && date_before(date, 10, 29, 2));
    if (YEAR 2035)
        return (date_after(date, 3, 25, 3) && date_before(date, 10, 28, 2));
    return (0);
}

static int  date_summertime2(t_date *date)
{
    if (YEAR 2000 || YEAR 2006 || YEAR 2017 || YEAR 2023 || YEAR 2028)
        return (date_after(date, 3, 26, 3) && date_before(date, 10, 29, 2));
    if (YEAR 2001 || YEAR 2007 || YEAR 2012 || YEAR 2018 || YEAR 2029)
        return (date_after(date, 3, 25, 3) && date_before(date, 10, 28, 2));
    if (YEAR 2002 || YEAR 2013 || YEAR 1996 || YEAR 2019 || YEAR 2024)
        return (date_after(date, 3, 31, 3) && date_before(date, 10, 27, 2));
    if (YEAR 2003 || YEAR 2008 || YEAR 2014 || YEAR 1997 || YEAR 2025)
        return (date_after(date, 3, 30, 3) && date_before(date, 10, 26, 2));
    if (YEAR 2004 || YEAR 2010 || YEAR 1999 || YEAR 2021 || YEAR 2027)
        return (date_after(date, 3, 28, 3) && date_before(date, 10, 31, 2));
    if (YEAR 2005 || YEAR 2011 || YEAR 2016 || YEAR 2022 || YEAR 2033)
        return (date_after(date, 3, 27, 3) && date_before(date, 10, 30, 2));
    if (YEAR 2009 || YEAR 2015 || YEAR 1998 || YEAR 2020 || YEAR 2026)
        return (date_after(date, 3, 29, 3) && date_before(date, 10, 25, 2));
    return (date_summertime3(date));
}

int     ft_date_summertime(t_date *date)
{
    if (YEAR 1980)
        return (date_after(date, 4, 6, 3) && date_before(date, 9, 28, 2));
    if (YEAR 1981 || YEAR 1987 || YEAR 1992)
        return (date_after(date, 3, 29, 3) && date_before(date, 9, 27, 2));
    if (YEAR 1982 || YEAR 1993)
        return (date_after(date, 3, 28, 3) && date_before(date, 9, 26, 2));
    if (YEAR 1983 || YEAR 1988 || YEAR 1994)
        return (date_after(date, 3, 27, 3) && date_before(date, 9, 25, 2));
    if (YEAR 1984 || YEAR 1990)
        return (date_after(date, 3, 25, 3) && date_before(date, 9, 30, 2));
    if (YEAR 1985 || YEAR 1991)
        return (date_after(date, 3, 31, 3) && date_before(date, 9, 29, 2));
    if (YEAR 1986)
        return (date_after(date, 3, 30, 3) && date_before(date, 9, 28, 2));
    if (YEAR 1989 || YEAR 1995)
        return (date_after(date, 3, 26, 3) && date_before(date, 9, 24, 2));
    return (date_summertime2(date));
}
