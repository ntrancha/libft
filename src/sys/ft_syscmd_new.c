/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:17:28 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/27 10:40:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/sys.h"
#include "../../includes/strings.h"

static void ft_syscmd_new_other(char *var, char *type, char *content)
{
    char    **tab;

    tab = NULL;
    if (ft_strcmp(type, "tabstr") == 0 || ft_strcmp(type, "liststr") == 0)
    {
        tab = ft_strsplit(content, content[0]);
        ft_alloc(tab, sizeof(char*), var, "tabstr");
        if (ft_strcmp(type, "liststr") == 0)
            ft_alloc_convert(var, type);
    }
}

static int  ft_syscmd_testok(char *var)
{
    if (ft_alloc_get(var) != NULL)
        return (1);
    return (0);
}

static int  ft_syscmd_test(char **tab)
{
    char    **tab2;
    char    *type;
    char    *var;
    char    *content;
    int     ret;

    type = ft_strsub(tab[0], 4, ft_strlen(tab[0]) - 5);
    if (!(tab2 = ft_strsplit(type, ' ')))
        return (0);
    ft_strdel(&type);
    if ((var = ft_strsub(tab2[1], 0, ft_strlen(tab2[1]))))
        if (ft_syscmd_testok(var))
            ft_alloc_del(var);
    type = ft_strsub(tab2[0], 0, ft_strlen(tab2[0]));
    content = ft_strsub(tab[1], 1, ft_strlen(tab[1]) - 1);
    if (ft_strcmp(type, "str") == 0)
        ft_calloc(content, ft_strlen(content) + 1, var, type);
    else if (ft_strcmp(type, "int") == 0)
        ft_sysint_alloc(ft_atoi(content), var);
    else
        ft_syscmd_new_other(var, type, content);
    ret = ft_syscmd_testok(var);
    ft_strdelth(&type, &var, &content);
    ft_tabstrdel(&tab2);
    return (ret);
}

int         ft_syscmd_new(char *str)
{
    char    **tab;
    int     ret;

    if (str && ft_strcchr(str, "=") != 0)
    {
        tab = ft_strsplit(str, '=');
        if (!tab)
            return (0);
        ret = ft_syscmd_test(tab);
        ft_tabstrdel(&tab);
        return (ret);
    }
    return (0);
}
