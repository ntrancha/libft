/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 19:46:12 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/15 20:12:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"
#include "../../includes/time.h"

int             ft_random_tabtest(int *tab, int size, int nbr)
{
    while (size >= 0)
        if (tab[size--] == nbr)
            return (1);
    return (0);
}

int             *ft_random_tabcreate(void)
{
    int         *tab;
    int         count;
    int         rand;

     if (!(tab = ft_memalloc(sizeof(int) * 100)))
        return (NULL);
    count = 0;
    while (count < 100)
    {
        rand = ft_rand(1, 100);
        if (ft_random_tabtest(tab, count, rand) == 0)
            tab[count++] = rand;
    }
    return (tab);
}

int             ft_random_hundred(void)
{
    static int  *tab;
    static int  count;

    if (!tab)
        tab = ft_random_tabcreate();
    return (tab[count++]);
}
