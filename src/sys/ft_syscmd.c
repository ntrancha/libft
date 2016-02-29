/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:06:43 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/29 20:50:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/sys.h"
/*
static char *ft_syscmd_getvarcontent(char *str)
{
    t_alloc *alloc;
    char    *tmp;
    int     start;
    int     id;

    start = (str[1] == '{') ? 2 : 1;
    id = (str[1] == '{') ? 1 : 0;
    tmp = ft_strsub(str, start, ft_strlen(str) - start - id);
    alloc = ft_alloc_get(tmp);
    ft_strdel(&tmp);
    if (alloc && ft_strcmp(alloc->type, "str") == 0)
        return ((char*)alloc->content);
    return (NULL);
}

static int  ft_syscmd_getvar(char **str)
{
    char    *ret;
    char    *tmp;
    int     start;
    int     id;

    if (ft_strcchr(*str, "$") == 0)
        return (0);
    id = 0;
    ret = ft_strdup(*str);
    while (ret[id] && ret[id] != '$')
        id++;
    start = id++;
    id += (ret[id] && ret[id] == '{') ? 1 : 0;
    while (ret[id] && !(END_CMD(ret[id])))
        id++;
    tmp = ft_strsub(ret, start, id - start + (ret[id] == '}'));
    ft_strdel(&ret);
    ret = ft_syscmd_getvarcontent(tmp);
    if (ret)
        ft_strreplace(str, tmp, ret, -1);
    ft_strdel(&tmp);
    if (ret)
        return (1);
    return (0);
}*/

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

    /*char    *tmp;
    char    *tmp2;
    int     ret;

    tmp2 = ft_strjoin(" ", str);
    ret = 1;
    while (ret == 1)
        ret = ft_syscmd_getvar(&tmp2);
    tmp = ft_strcleanfront(tmp2, ' ');
    ft_strdel(&tmp2);
    if (ft_strncmp(tmp, "new", 3) == 0 && ft_strcchr(tmp, "(") == 0)
        ft_syscmd_new(tmp);
    else if (ft_strncmp(tmp, "echo", 4) == 0)
        ft_syscmd_echo(tmp);
    else if (tmp[0] == '#')
        ft_syscmd_sys(tmp);
    else if (ft_strcchr(tmp, "=") == 0)
        ft_syscmd_func(tmp);
    else
        ft_syscmd_var(&tmp);
    ft_strdel(&tmp);*/
}

static int  no_comment(char *str)
{
    int     len;

    len = ft_strlen(str);
    if (len > 0 && str[0] == '/' && str[1] == '/')
        return (0);
    if (len > 0 && str[0] == '/' && str[1] == '*')
        return (0);
    if (len > 0 && str[0] == '<' && str[1] == '?')
        return (0);
    if (len > 0 && str[0] == '?' && str[1] == '>')
        return (0);
    if (len > 0 && str[0] == '#' && str[1] == '!')
        return (0);
    return (1);
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
    else if (no_comment(tmp))
        ft_syscmd__type(tmp);
    ft_strdel(&tmp);
    return (str);
}
