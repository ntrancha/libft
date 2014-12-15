/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 12:17:21 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/15 12:17:21 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

int     ft_tabmin(t_tab *tab)
{
    int min;
    int i;
    int j;

    i = 0;
    min = 0;
    while (i < tab->col)
    {
        j = 0;
        while (j < tab->line)
        {
            if (tab->tab[i][j] > min)
                min = tab->tab[i][j];
            j++;
        }
        i++;
    }
    return (min);
}
