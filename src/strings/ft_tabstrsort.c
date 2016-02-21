/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 23:27:25 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/22 00:12:34 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/count.h"

static int  ft_tabstrissort(char **tab, int sort)
{
    int     index;
    int     test;

    index = -1;
    while (tab[++index] && tab[index + 1])
    {
        test = ft_strcmp(tab[index], tab[index + 1]);
        if (test && !((test > 0 && sort > 0) || (test < 0 && sort < 0)))
            return (0);

    }
    return (1);
}

void        ft_tabstrsort(char ***tab, int sort)
{
    int     index;
    int     test;
    int     lock;
    char    *tmp;

    if (!ft_tabstrissort(*tab, sort * -1))
    {
        lock = 1;
        index = -1;
        while ((*tab)[++index] && (*tab)[index + 1] && lock)
        {
            test = ft_strcmp((*tab)[index], (*tab)[index + 1]);
            if (test && !((test > 0 && sort < 0) || (test < 0 && sort > 0)))
            {
                tmp = (*tab)[index];
                (*tab)[index] = (*tab)[index + 1];
                (*tab)[index + 1] = tmp;
                lock = 0;
                ft_tabstrsort(tab, sort);
            }
        }
    }
}
