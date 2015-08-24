/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenbuffering.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 20:33:40 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:08:05 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"
#include "../../includes/strings.h"

static void    addinbuff_str(char *str)
{
    t_screen    *screen;

    screen = ft_screeninit();
    screen->buffer = ft_caseadd(screen->buffer, str, NULL);
    screen->offset++;
}

static  void    addinbuff(t_case *cases)
{
    t_screen    *screen;

    screen = ft_screeninit();
    screen->buffer = ft_caseadd(screen->buffer, cases->str, cases->spec);
    screen->offset++;
}

static void     newl(void)
{
    t_screen    *screen;

    screen = ft_screeninit();
    screen->offset = 0;
    screen->line++;
}

static void     endl(char *spec)
{
    t_screen    *screen;
    int         col;

    screen = ft_screeninit();
    if (screen)
    {
        col = ft_screenget_col();
        while (screen->offset++ < col)
            screen->buffer = ft_caseadd(screen->buffer, " ", spec);
        newl();
    }
}

static void	supression(void)
{
    t_screen    *screen;

    screen = ft_screeninit();
    screen->buffer = ft_casedelend(screen->buffer);
	if (screen->offset == 0)
    {
		if (screen->line > 1)
		{
			screen->line--;
			screen->offset = ft_screenget_col() - 1;
		}
    }
    else
        screen->offset--;
}

static void     tabulation(void)
{
    addinbuff_str(" ");
    if (ft_screenget_offset() + 3 >= ft_screenget_col())
        endl(NULL);
    else
        while (ft_screenget_offset() % 4 != 0)
            addinbuff_str(" ");
}

void            ft_screenbuffering(void)
{
    t_screen    *screen;
    t_case      *jump;
    int         col;

    col = ft_screenget_col();
    if ((screen = ft_screeninit()))
    {
        if (screen->buffer != NULL)
            ft_casesdel(screen->buffer);
        jump = screen->original;
        while (jump)
        {
            if (jump->str[0] == '\n')
                endl(jump->spec);
			else if (jump->str[0] == '\b')
				supression();
			else if (jump->str[0] == '\t')
				tabulation();
            else
                addinbuff(jump);
            if (screen->offset >= col)
                newl();
            jump = jump->next;
        }
    }
}
