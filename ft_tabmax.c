/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 12:19:23 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/15 12:19:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

int     ft_tabmax(t_tab *tab)
{
    int max;
    int i;
    int j;

    i = 0;
    max = 0;
    while (i < tab->col)
    {
        j = 0;
        while (j < tab->line)
        {
            if (tab->tab[i][j] > max)
                max = tab->tab[i][j];
            j++;
        }
        i++;
    }
    return (max);
}
