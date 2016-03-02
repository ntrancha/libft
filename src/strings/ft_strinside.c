/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinside.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 20:45:36 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/01 21:03:05 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

int         find_first(char *str, int index, char c)
{
    while (str[++index])
        if (str[index] == c)
            return (index);
    return (0);
}

int         find_last(char *str, char c)
{
    int     index;
    int     ret;

    index = -1;
    ret = 0;
    while (str[++index])
        if (str[index] == c)
            ret = index;
    return (ret);
}

char        *ft_strinside(char *str, char start, char end)
{
    int     first;
    int     last;
    char    *inside;

    last = find_last(str, start);
    first = find_first(str, last, end);
    inside = ft_strsub(str, last + 1, first - last - 1);
    return (inside);
}
