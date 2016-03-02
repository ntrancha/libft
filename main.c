/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/02 22:45:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int         grep_signe(char *str)
{
    if (ft_strcchr(str, " == "))
        return (1);
    if (ft_strcchr(str, " != "))
        return (2);
    if (ft_strcchr(str, " < "))
        return (3);
    if (ft_strcchr(str, " > "))
        return (4);
    if (ft_strcchr(str, " <= "))
        return (5);
    if (ft_strcchr(str, " >= "))
        return (6);
    return (0);
}

char        *recup_one(char *str, int type)
{
    char    *ret;
    char    **tab;

    if (type == 1 || type == 2)
        tab = ft_strsplit(str, '=');
    if (type == 3 || type == 5)
        tab = ft_strsplit(str, '<');
    if (type == 4 || type == 6)
        tab = ft_strsplit(str, '>');
    if (type == 2)
        ret = ft_strsub(tab[0], 0, ft_strlen(tab[0]) - 2);
    else
        ret = ft_strsub(tab[0], 0, ft_strlen(tab[0]) - 1);
    ft_tabstrdel(&tab);
    return (ret);
}

int         var_type(char *var)
{
    t_alloc *alloc;

    if (ft_strisnum(var))
        return (1);
    if (var[0] == '"' && var[ft_strlen(var) - 1] == '"')
        return (2);
    alloc = ft_alloc_get(var);
    if (!alloc)
        return (0);
    if (ft_strcmp(alloc->type, "str") == 0)
        return (22);
    if (ft_strcmp(alloc->type, "int") == 0)
        return (11);
    return (0);
}

char        *recup_two(char *str, int type)
{
    char    *ret;
    char    **tab;

    if (type == 1 || type == 2)
        tab = ft_strsplit(str, '=');
    if (type == 3 || type == 5)
        tab = ft_strsplit(str, '<');
    if (type == 4 || type == 6)
        tab = ft_strsplit(str, '>');
    if (type == 6 || type == 5)
        ret = ft_strsub(tab[1], 2, ft_strlen(tab[1]) - 2);
    else
        ret = ft_strsub(tab[1], 1, ft_strlen(tab[1]) - 1);
    ft_tabstrdel(&tab);
    return (ret);
}

int         resolve_int(char *one, char *two, int signe)
{
    int     int_one;
    int     int_two;

    int_one = ft_atoi(one);
    int_two = ft_atoi(two);
    if (signe == 1)
        return ((int_one == int_two));
    if (signe == 2)
        return ((int_one != int_two));
    if (signe == 3)
        return ((int_one < int_two));
    if (signe == 4)
        return ((int_one > int_two));
    if (signe == 5)
        return ((int_one <= int_two));
    if (signe == 6)
        return ((int_one >= int_two));
    return (0);
}

int         ft_syscmdresolve(char *one, char *two, int signe)
{
    int     type_one;
    int     type_two;
    int     *tmp;
    char    *str;

    type_one = var_type(one);
    type_two = var_type(two);
    if (type_one == 1 && type_two == 1)
        resolve_int(one, two, signe);
    else if (type_one == 11 && type_two == 1)
    {
        tmp = (int*)ft_alloc_vget(one);
        str = ft_itoa(*tmp);
        resolve_int(str, two, signe);
        ft_strdel(&str);
    }

}

int         ft_syscmd_true(char *str)
{
    char    *inside;
    char    *one;
    char    *two;
    int     resolve;

    inside = ft_strinside(str, '(', ')');
    one = recup_one(inside, grep_signe(inside));
    two = recup_two(inside, grep_signe(inside));
    resolve = ft_syscmdresolve(one, two, grep_signe(inside));
    ft_strdelth(&one, &two, &inside);
    return (0);
}


int         ft_main(void)
{
    char    *str;

    ft_syscmd_file("code.php");
    str = ft_strdup("LEN > 0 && LEN != 0 && LEN < 100 - 1");
    ft_putnbr_endl(ft_syscmd_resolve_all(str));
    ft_strdel(&str);
    return 1;
}

FT_MAIN
