/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_resolve_all.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 22:40:23 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/02 22:42:06 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/convert.h"

static int  is_op(char *str)
{
    if (ft_strcmp(str, "&&") == 0 || ft_strcmp(str, "||") == 0)
        return (3);
    if (ft_strcmp(str, "==") == 0 || ft_strcmp(str, "!=") == 0)
        return (2);
    if (ft_strcmp(str, "<") == 0 || ft_strcmp(str, ">") == 0)
        return (2);
    if (ft_strcmp(str, "<=") == 0 || ft_strcmp(str, ">=") == 0)
        return (2);
    if (ft_strcmp(str, "-") == 0 || ft_strcmp(str, "+") == 0)
        return (1);
    if (ft_strcmp(str, "*") == 0 || ft_strcmp(str, "/") == 0)
        return (1);
    if (ft_strcmp(str, "%") == 0)
        return (1);
    return (0);
}


static char *resolve_fusion(char *one, char *two, char *op)
{
    char    *tmp;
    char    *ret;

    tmp = ft_strmmjoin(one, " ", op, " ");
    ret = ft_strjoin(tmp, two);
    ft_strdel(&tmp);
    return (ret);
}

static int  resolve_all(char **str, int op)
{
    char    **tab;
    int     index;
    char    *fus;
    char    *ret;

    index = -1;
    tab = ft_strsplit(*str, ' ');
    while (tab[++index])
    {
        if (index > 1 && is_op(tab[index - 1]) == op)
        {
            fus = resolve_fusion(tab[index - 2], tab[index], tab[index - 1]);
            ret = ft_itoa(ft_syscmd_resolve(tab[index - 2], tab[index], tab[index - 1]));
            ft_strreplace(str, fus, ret, -1);
            ft_strdelt(&fus, &ret);
            ft_tabstrdel(&tab);
            return (1);
        }
    }
    ft_tabstrdel(&tab);
    return (0);
}

int         ft_syscmd_resolve_all(char *str)
{
    char    *copy;
    int     index;

    copy = ft_strdup(str);
    index = 0;
    while (resolve_all(&copy, 1))
        index ++;
    while (resolve_all(&copy, 2))
        index ++;
    while (resolve_all(&copy, 3))
        index ++;
    index = ft_atoi(copy);
    ft_strdel(&copy);
    return (index);
}
