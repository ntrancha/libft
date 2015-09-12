/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addsubstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 12:32:20 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/12 12:56:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int     neg(char *str)
{
    if (str[0] == '-')
        return (1);
    return (0);
}

char        *absolute(char *str)
{
    char    *ret;

    if (neg(str) == 1)
        ret = ft_strsub(str, 1, (int)ft_strlen(str) - 1);
    else
        ret = ft_strdup(str);
    return (ret);
}

char        *operation(char *a, char *b, int neg, int op)
{
    char    *tmp;

    if (op == 1)
        tmp = ft_addstr(a,b);
    else
        tmp = ft_substr(a,b);
    if (neg == 1)
        ft_straddcharf(&tmp, '-');
    return (tmp);
}

char    *ft_addsubstr(char *a, char *b, int op)
{
    char    *abs_a;
    char    *abs_b;
    char    *ret;

    abs_a = absolute(a);
    abs_b = absolute(b);
    if (op == 1)
    {
        if (neg(a) && neg(b))
            ret = operation(abs_a, abs_b, 1, 1);
        if (neg(a) && !neg(b) && ft_strcmp(abs_a, abs_b) >= 0)
            ret = operation(abs_a, abs_b, 1, -1);
        if (neg(a) && !neg(b) && ft_strcmp(abs_a, abs_b) < 0)
            ret = operation(abs_a, abs_b, 0, -1);
        if (!neg(a) && !neg(b))
            ret = operation(abs_a, abs_b, 0, 1);
    }
    ft_strdel(&abs_a);
    ft_strdel(&abs_b);
    return (ret);
}
