/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 11:07:26 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/12 11:45:07 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int         strlennum(char *str)
{
    int     ret;

    ret = ft_strlen(str);
    if (str[0] == '-')
        ret--;
    return (ret);
}

int         num(char c)
{
    return (c - 48);
}

void        addstr(char *a, char *b, char *ret)
{
    int     index;
    int     index2;
    int     result;
    int     retenu;

    index = ft_strlen(a);
    index2 = ft_strlen(ret);
    retenu = 0;
    ft_putendl(a);
    ft_putendl(b);
    while (--index >= 0)
    {
        result = num(a[index]) + num(b[index]) + retenu;
        retenu = 0;
        if (result > 9)
        {
            retenu = 1;
            result -= 10;
        }
        ret[index2--] = result + 48;
    }
    if (retenu)
        ret[0] = '1';
}

char        *ft_addstr(char *a, char *b)
{
    char    *ret;
    char    *tmp_a;
    char    *tmp_b;

    tmp_a = ft_strdup(a);
    tmp_b = ft_strdup(b);
    while (strlennum(tmp_a) < strlennum(tmp_b))
        ft_straddcharf(&tmp_a, '0');
    while (strlennum(tmp_b) < strlennum(tmp_a))
        ft_straddcharf(&tmp_b, '0');
    ret = ft_strint(ft_strlen(tmp_a));
    addstr(tmp_a, tmp_b, ret);
    ft_strdel(&tmp_a);
    ft_strdel(&tmp_b);
    return (ret);
}
