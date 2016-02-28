/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 01:32:30 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/28 01:50:44 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/strings.h"

static int  test_var(char *str)
{
    char    *tmp;
    int     ret;
    int     index;
    int     test;

    tmp = ft_strdup(str);
    ret = 0;
    ft_syscmd_clean(&tmp);
    if (ft_strncmp(tmp, "new", 3) == 0)
        ret = 30;
    if (ft_strcchr(tmp, "=") == 0)
        ret = 0;
    index = -1;
    test = 0;
    while (tmp[++index])
    {
        if (tmp[index] == ' ')
            test++;
        else if (tmp[index] == '=' && (test == 3 || test == 1))
            test = -200000000;
    }
    ft_strdel(&tmp);
    if (test < 0)
        return (30);
    return (ret);
}

static int  test_system(char *str)
{
    char    *tmp;
    int     ret;

    tmp = ft_strdup(str);
    ret = 0;
    ft_syscmd_clean(&tmp);
    if (ft_strncmp(tmp, "echo", 4) == 0)
        ret = 11;
    if (ft_strncmp(tmp, "#", 1) == 0)
        ret = 12;
    ft_strdel(&tmp);
    return (ret);
}

static int  test_function(char *str)
{
    char    *tmp;
    int     ret;

    tmp = ft_strdup(str);
    ret = 0;
    ft_syscmd_clean(&tmp);
    if (ft_strcchr(tmp, "(") != 0 && ft_strcchr(tmp, ")") != 0)
        ret = 20;
    ft_strdel(&tmp);
    return (ret);
}

static int  test_condition(char *str)
{
    char    *tmp;
    int     ret;

    tmp = ft_strdup(str);
    ret = 0;
    ft_syscmd_clean(&tmp);
    if (ft_strncmp(tmp, "if", 2) == 0)
        ret = 1;
    if (ft_strncmp(tmp, "while", 5) == 0)
        ret = 2;
    if (ft_strncmp(tmp, "else", 4) == 0)
        ret = 3;
    if (ft_strncmp(tmp, "{", 1) == 0)
        ret = 4;
    if (ft_strncmp(tmp, "}", 1) == 0)
        ret = 5;
    ft_strdel(&tmp);
    return (ret);
}

int         ft_syscmd_type(char *str)
{
    int     type;
    int     len;

    len = ft_strlen(str);
    if (len > 1 && str[0] == '/' && str[1] == '/')
        return (42);
    if (len > 1 && str[0] == '<' && str[1] == '?')
        return (42);
    if (len > 1 && str[0] == '?' && str[1] == '>')
        return (42);
    if (len > 1 && str[0] == '#' && str[1] == '!')
        return (42);
    type = -1;
    if ((type = test_condition(str)) == 0)
        if ((type = test_system(str)) == 0)
            if ((type = test_var(str)) == 0)
                type = test_function(str);
    return (type);
}
