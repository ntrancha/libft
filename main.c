/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/28 21:15:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int  type_ass(char *str)
{
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
    ft_strclearfront(&tmp, '[');
    ft_strclearback(&tmp, ']');
    tab = ft_strsplit(tmp, ',');
    index = -1;
    while (tab && tab[++index])
    {
        ft_syscmd_clean(&tab[index]);
        ft_strunquote(&tab[index], '"');
    }
    ft_alloc((void*)tab, sizeof(char*), var_name, type);
    ft_strdel(&tmp);
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
        ft_tabstrdel(&tab);
    }
    ft_strdel(&tmp);
}

int         syscmd_var(char *str)
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
    if (ft_strncmp(var, "new ", 4) == 0 || ft_strncmp(var, "NEW ", 4) == 0)
        new_var(var, ass);
    ft_strdelt(&var, &ass);
}

int         ft_main(void)
{
    syscmd_var("new tabstr VAR_NAME = [\"1\", \"2\", \"3\", \"5\"]");
    syscmd_var("iest = TIMESTAP");
    ft_syscmd_file("code.php");
    return 1;
}

FT_MAIN
