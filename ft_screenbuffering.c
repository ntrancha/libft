/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenbuffering.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 20:33:40 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 22:15:56 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void     newl(void)
{
    t_screen    *screen;

    screen = ft_screeninit();
    screen->offset = 0;
    screen->line++;
}

static void     endl(int col, char *spec)
{
    t_screen    *screen;

    screen = ft_screeninit();
    while (screen->offset++ < col)
        screen->buffer = ft_caseadd(screen->buffer, " ", spec);
    newl();
}

static void	supression(int col)
{
    t_screen    *screen;

    screen = ft_screeninit();
    screen->buffer = ft_casedelend(screen->buffer);
	if (screen->offset == 0)
		if (screen->line > 1)
		{
			screen->line--;
			screen->offset = col - 1;
		}
}

void            ft_screenbuffering(void)
{
    t_screen    *screen;
    t_case      *jump;
    int         col;
    //int         row;
    //int         line;

    col = ft_screenget_col();
    //row = ft_screenget_row();
    screen = ft_screeninit();
    if (screen)
    {
        if (screen->buffer != NULL)
            ft_casesdel(screen->buffer);
        jump = screen->original;
        while (jump)
        {
            if (jump->str[0] == '\n')
                endl(col, jump->spec);
			else if (jump->str[0] == '\b')
				supression(col);
            else
            {
                screen->buffer = ft_caseadd(screen->buffer, jump->str, jump->spec);
                screen->offset++;
            }
            if (screen->offset >= col)
                newl();
            jump = jump->next;
        }
    }
}
