/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 12:20:06 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:40:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/put.h"
#include "../../includes/tab.h"

int     ft_puttab(t_tab *tab)
{
    int line;
    int col;

    col = 0;
    if (tab == NULL || tab->tab == NULL)
        return (-1);
    while (col < tab->col)
    {
        line = 0;
        while (line < tab->line)
        {
            ft_putnbr(tab->tab[col][line]);
            ft_putchar('\t');
            line++;
        }
        ft_putchar('\n');
        col++;
    }
    return (0);
}
