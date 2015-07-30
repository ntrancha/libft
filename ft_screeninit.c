/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screeninit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 05:47:08 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 07:09:16 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_screen            *ft_screeninit(void)
{
    static t_screen *screen;

    if (!screen)
    {
        screen = ft_memalloc(sizeof(t_screen));
        if (!screen)
            return (NULL);
        screen->row = ft_getrow();
        screen->col = ft_getcol();
        screen->offset = 0;
        screen->size = 0;
        screen->buffer = NULL;
    }
    return (screen);
}
