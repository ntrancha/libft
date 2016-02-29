/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:06:43 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/29 20:55:29 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/sys.h"

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
        ft_syscmd__type(tmp);
    ft_strdel(&tmp);
    return (str);
}
