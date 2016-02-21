/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrtostr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 19:26:24 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/21 21:21:41 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/mem.h"
#include "../../includes/count.h"

char        *ft_tabstrtostr(char **tab)
{
    char    *ret;
    int     index;
    int     c_tab;
    int     c_ret;

    ret = ft_memalloc(sizeof(char) * ft_tabstrlen(tab) + 1);
    if (!ret)
        return (NULL);
    index = -1;
    c_ret = 0;
    while (tab[++index])
    {
        c_tab = -1;
        while (tab[index][++c_tab])
            ret[c_ret++] = tab[index][c_tab];
    }
    ret[c_ret] = '\0';
    return (ret);
}
