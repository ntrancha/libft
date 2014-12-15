/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 12:21:06 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/15 12:21:06 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void    ft_tabclear(t_tab *tab)
{
    int line;
    int col;

    col = 0;
    while (col < tab->col)
    {
        line = 0;
        while (line < tab->line)
        {
            tab->tab[col][line] = 0;
            line++;
        }
        col++;
    }
}
