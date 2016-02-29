/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:17:28 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/28 23:01:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/sys.h"
#include "../../includes/strings.h"
#include "../../includes/test.h"
#include "../../includes/count.h"

static int  type_ass(char *str)
{
    if (!str)
        return (0);
    if (ft_strisnum(str) == 1)
        return (1);
    if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
        return (2);
    if (ft_strcchr(str, "(") != 0 && str[ft_strlen(str) - 1] == ')')
        return (3);
    if (ft_alloc_get(str) != NULL)
        return (4);
    if (str[0] == '[' && str[ft_strlen(str) - 1] == ']')
    {
        if (str[1] == '"' && str[ft_strlen(str) - 2] == '"')
            return (5);
        else
            return (6);
    }
    return (0);
}

static void new_tabstr(char *type, char *var_name, char *content)
{
    char    *tmp;
    int     index;
    char    **tab;

    tmp = ft_strdup(content);
    if (tmp && ft_strcchr(tmp, ",") != 0 && var_name && type )
    {
        ft_strclearfront(&tmp, '[');
        ft_strclearback(&tmp, ']');
        tab = ft_strsplit(tmp, ',');
        index = -1;
        if (tab)
        {
            while (tab && tab[++index])
            {
                ft_syscmd_clean(&tab[index]);
                ft_strunquote(&tab[index], '"');
            }
            ft_alloc((void*)tab, sizeof(char*), var_name, "tabstr");
            if (ft_strcmp(type, "liststr") == 0)
                ft_alloc_cnvrt(var_name, type);
        }
        ft_strdel(&tmp);
    }
}

static void funcadd(char *var, char *ass)
{
    char    *one;
    char    *tmp;

    if (var && ass)
    {
        one = ft_strsub(var, 0, ft_strlen(var) - 1);
        if (one)
        {
            if (one[ft_strlen(one) - 1] != '(')
                tmp = ft_strmmjoin(one, ", ", ass, ")");
            else
                tmp = ft_strmjoin(one, ass, ")");
            if (tmp)
            {
                ft_syscmd(tmp);
                ft_strdel(&tmp);
            }
        }
        ft_strdel(&one);
    }
}

static void new_var(char *var, char *ass)
{
    char    **tab;
    char    *str;
    char    *tmp;

    tmp = ft_strsub(var, 4, ft_strlen(var) - 4);
    ft_syscmd_clean(&tmp);
    if (ft_strcchr(tmp, " ") == 1)
    {
        tab = ft_strsplit(tmp, ' ');
        if (type_ass(ass) == 1 && ft_strcmp(tab[0], "int") == 0)
            ft_sysint_alloc(ft_atoi(ass), tab[1]);
        else if (type_ass(ass) == 2 && ft_strcmp(tab[0], "str") == 0)
        {
            str = ft_strdup(ass);
            ft_strunquote(&str, '"');
            ft_alloc((void*)str, ft_strlen(str) + 1, tab[1], "str");
        }
        else if (type_ass(ass) == 5 && ft_strcmp(tab[0], "tabstr") == 0)
            new_tabstr(tab[0], tab[1], ass);
        else if (type_ass(ass) == 5 && ft_strcmp(tab[0], "liststr") == 0)
            new_tabstr(tab[0], tab[1], ass);
        ft_tabstrdel(&tab);
    }
    ft_strdel(&tmp);
}

int         ft_syscmd_new(char *str)
{
    char    **tab;
    char    *var;
    char    *ass;

    tab = ft_strsplit(str, '=');
    var = ft_strdup(tab[0]);
    ass = ft_strsub(str, ft_strlen(var) + 1, ft_strlen(str) - ft_strlen(var));
    ft_syscmd_clean(&var);
    ft_syscmd_clean(&ass);
    ft_tabstrdel(&tab);
    if (type_ass(ass) == 4)
        ft_alloc_copy(ass, var);
    else if (type_ass(ass) == 3)
        funcadd(ass, var);
    else if (ft_strncmp(var, "new ", 4) == 0 || ft_strncmp(var, "NEW ", 4) == 0)
        new_var(var, ass);
    ft_strdelt(&var, &ass);
    return (1);
}
