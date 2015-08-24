/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:20:10 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:09:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"
#include "../../includes/strings.h"

void            ft_screenclear(void)
{
    t_screen    *screen;

    screen = ft_screeninit();
    screen->cursor = 0;
    screen->size = 0;
    if (screen->buffer != NULL)
        ft_casesdel(screen->buffer);
    screen->buffer = NULL;
    if (screen->original != NULL)
        ft_casesdel(screen->original);
    screen->original = NULL;
}
