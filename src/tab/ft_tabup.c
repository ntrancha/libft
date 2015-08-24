/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 08:53:40 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:45:29 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"

void	ft_tabup(t_tab *tab, int up)
{
    int	i;
    int	j;

    i = -1;
    while (++i < tab->col)
    {
        j = 0;
        while (j < tab->line)
            tab->tab[i][j++] += up;
    }
}
