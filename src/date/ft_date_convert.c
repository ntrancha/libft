/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 09:50:56 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 00:30:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/date.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"
#include "../../includes/convert.h"

t_date      *date_create(void)
{
    t_date  *date;

    date = ft_memalloc(sizeof(t_date));
    if (!date)
        return (date);
    date->seconde = 0;
    date->minute = 0;
    date->hour = 0;
    date->month = 0;
    date->day = 0;
    date->year = 0;
    return (date);
}

void        date_convert_date(char *str, t_date *date)
{
    char    **tmp;

    if (str)
    {
        tmp = ft_strsplit(str, '/');
        if (tmp != NULL && tmp[1] != NULL && tmp[2] != NULL)
        {
            date->day = ft_atoi(tmp[0]);
            date->month = ft_atoi(tmp[1]);
            date->year = ft_atoi(tmp[2]);
        }
        if (tmp != NULL)
            ft_tabstrdel(&tmp);
    }
}

void        date_convert_time(char *str, t_date *date)
{
    char    **tmp;

    if (str)
    {
        tmp = ft_strsplit(str, ':');
        if (tmp != NULL && tmp[1] != NULL && tmp[2] != NULL)
        {
            date->hour = ft_atoi(tmp[0]);
            date->minute = ft_atoi(tmp[1]);
            date->seconde = ft_atoi(tmp[2]);
        }
        if (tmp != NULL)
            ft_tabstrdel(&tmp);
    }
}

int         count_char(char *str, char c)
{
    int     ret;

    ret = 0;
    while (str++ && *str)
        if (*str == c)
            ret++;
    return (ret);
}

t_date      *ft_date_convert(char *str)
{
    char    **ret;
    t_date  *date;

    ret = ft_strsplit(str, ' ');
    if (count_char(str, ' ') != 1)
        return (NULL);
    if (count_char(str, '/') != 2)
        return (NULL);
    if (count_char(str, ':') != 2)
        return (NULL);
    if (ret != NULL && ret[1] != NULL && !ret[2])
    {
        if (!(date = date_create()))
            return (NULL);
        date_convert_time(ret[0], date);
        date_convert_date(ret[1], date);
        ft_tabstrdel(&ret);
        return (date);
    }
    return (NULL);
}
