/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 21:09:03 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/01 02:29:26 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void            ft_screenfree(void)
{
    t_screen    *screen;

    screen = ft_screeninit();
    if (screen != NULL)
    {
        if (screen->buffer != NULL)
            ft_casesdel(screen->buffer);
        if (screen->original != NULL)
            ft_casesdel(screen->original);
        free(screen);
    }
    write(1, C_NULL, 4);
}