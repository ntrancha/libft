/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/28 20:38:37 by ntrancha         ###   ########.fr       */
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

static void new_var(char *var, char *ass)
{
    char    **tab;
    char    *tmp;

    tmp = ft_strsub(var, 4, ft_strlen(var) - 4);
    ft_syscmd_clean(&tmp);
    if (ft_strcchr(tmp, " ") == 1)
    {
        tab = ft_strsplit(tmp, ' ');
        if (type_ass(ass) == 1 && ft_strcmp(tab[0], "int") == 0)
            ft_sysint_alloc(ft_atoi(ass), tab[1]);
        if (type_ass(ass) == 2 && ft_strcmp(tab[0], "str") == 0)
            ft_calloc((void*)ass, ft_strlen(ass) + 1, tab[1], "str");
        ft_putendl(tab[1]);
        ft_putendl(tab[0]);
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
    syscmd_var("new TYPE VAR_NAME = \"==\"");
    syscmd_var("iest = TIMESTAP");
    /*ft_syscmd_file("code.php");*/
    return 1;
}

FT_MAIN
