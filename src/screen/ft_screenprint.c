/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:40:08 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:13:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"
#include "../../includes/put.h"

void            ft_screenprint(void)
{
    t_case      *jump;
    t_screen    *screen;

    ft_screenbuffering();
    screen = ft_screeninit();
    jump = screen->buffer;
    while (jump)
    {
        if (jump->spec != NULL)
            ft_putstr(jump->spec);
        ft_putstr(jump->str);
        jump = jump->next;
    }
    ft_casesdel(screen->buffer);
    screen->buffer = NULL;
}
