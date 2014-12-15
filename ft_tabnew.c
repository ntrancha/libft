/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 05:49:43 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/15 05:49:43 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

int		**ft_tabnew(int line, int col)
{
    int	**tab;
    int	*tab2;
    int	i;

    tab = (int **)malloc(sizeof(int*) * line);
    tab2 = (int *)malloc(sizeof(int) * col * line);
    i = 0;
    while (i < line)
    {
        tab[i] = &tab2[i * col];
        i++;
    }
    return (tab);
}
