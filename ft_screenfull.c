/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenfull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:53:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/01 01:59:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void            ft_screenfull(char c, char *spec)
{
    int         col;
    int         row;
    t_screen    *screen;

    screen = ft_screeninit();
    row = 0;
    while (row < screen->row)
    {
        col = 0;
        while (col < screen->col)
        {
            ft_screenwrite_char(c, spec);
            col++;
        }
        row++;
    }
}
