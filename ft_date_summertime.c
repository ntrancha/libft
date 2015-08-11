/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_summertime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 01:41:11 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/11 04:41:17 by ntrancha         ###   ########.fr       */
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
        return (BETWEEN(31, 27));
    if (YEAR 2031 || YEAR 2036)
        return (BETWEEN(30, 26));
    if (YEAR 2037)
        return (BETWEEN(29, 25));
    if (YEAR 2032)
        return (BETWEEN(28, 31));
    if (YEAR 2034)
        return (BETWEEN(26, 29));
    if (YEAR 2035)
        return (BETWEEN(25, 28));
    return (0);
}

static int  date_summertime2(t_date *date)
{
    if (YEAR 2000 || YEAR 2006 || YEAR 2017 || YEAR 2023 || YEAR 2028)
        return (BETWEEN(26, 29));
    if (YEAR 2001 || YEAR 2007 || YEAR 2012 || YEAR 2018 || YEAR 2029)
        return (BETWEEN(25, 28));
    if (YEAR 2002 || YEAR 2013 || YEAR 1996 || YEAR 2019 || YEAR 2024)
        return (BETWEEN(31, 27));
    if (YEAR 2003 || YEAR 2008 || YEAR 2014 || YEAR 1997 || YEAR 2025)
        return (BETWEEN(30, 26));
    if (YEAR 2004 || YEAR 2010 || YEAR 1999 || YEAR 2021 || YEAR 2027)
        return (BETWEEN(28, 31));
    if (YEAR 2005 || YEAR 2011 || YEAR 2016 || YEAR 2022 || YEAR 2033)
        return (BETWEEN(27, 30));
    if (YEAR 2009 || YEAR 2015 || YEAR 1998 || YEAR 2020 || YEAR 2026)
        return (BETWEEN(29, 25));
    return (date_summertime3(date));
}

int     ft_date_summertime(t_date *date)
{
    if (YEAR 1980)
        return (date_after(date, 4, 6, 3) && date_before(date, 9, 28, 2));
    if (YEAR 1981 || YEAR 1987 || YEAR 1992)
        return (BETWEEN(29, 27));
    if (YEAR 1982 || YEAR 1993)
        return (BETWEEN(28, 26));
    if (YEAR 1983 || YEAR 1988 || YEAR 1994)
        return (BETWEEN(27, 25));
    if (YEAR 1984 || YEAR 1990)
        return (BETWEEN(25, 30));
    if (YEAR 1985 || YEAR 1991)
        return (BETWEEN(31, 29));
    if (YEAR 1986)
        return (BETWEEN(30, 28));
    if (YEAR 1989 || YEAR 1995)
        return (BETWEEN(26, 24));
    return (date_summertime2(date));
}
