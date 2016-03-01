/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:06:43 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/01 12:04:00 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/sys.h"

static void ft_syscmd_replace(char **str, char *var)
{
    char    *old;
    char    *new;
    t_alloc *alloc;

    alloc = ft_alloc_get(var);
    if (alloc && ft_strcmp(alloc->type, "str") == 0)
    {
        old = ft_strmjoin("${", var, "}");
        new = ft_strdup(alloc->content);
        ft_strreplace(str, old, new, -1);
        ft_strdelt(&old, &new);
    }
}

static void ft_syscmd_transforme(char **str)
{
    char    *src;
    char    *new;
    int     index;
    int     start;
    int     end;

    src = *str;
    index = -1;
    start = 0;
    end = 0;
    if (ft_strcchr(src, "${") != 0 && ft_strcchr(src, "}") != 0)
    {
        while (src[++index] && end == 0)
            if (start == 0 && src[index] == '$' && src[index + 1] == '{')
                start = index + 2;
            else if (start != 0 && end == 0 && src[index] == '}')
                end = index;
        new = ft_strsub(src, start, end - start);
        ft_syscmd_replace(str, new);
        ft_strdel(&new);
    }
    if (end)
        ft_syscmd_transforme(str);
}

static void ft_syscmd__type(char *str)
{
    int     type;

    type = ft_syscmd_type(str);
    if (type == 20)
        ft_syscmd_func(str);
    else if (type == 30)
        ft_syscmd_new(str);
    else if (type == 11)
        ft_syscmd_echo(str);
    else if (type == 12)
        ft_syscmd_sys(str);
    else if (type > 0 && type < 4)
        ft_putendl(str);
}

void        *ft_syscmd(char *str)
{
    char    **tab;
    char    *tmp;
    int     index;

    tmp = ft_strdup(str);
    ft_syscmd_clean(&tmp);
    ft_strdoublon(&tmp, ';');
    if (ft_strcchr(tmp, ";") != 0)
    {
        tab = ft_strsplit(tmp, ';');
        index = -1;
        while (tab[++index])
            ft_syscmd(tab[index]);
        ft_tabstrdel(&tab);
    }
    else
    {
        ft_syscmd_transforme(&tmp);
        ft_syscmd__type(tmp);
    }
    ft_strdel(&tmp);
    return (str);
}
