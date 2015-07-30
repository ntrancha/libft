/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:40:08 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 07:46:19 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void     putendl(int nspace, char space, char *spec)
{
    int         count;

    count = 0;
    while (count < nspace)
    {
        if (spec)
            ft_putstr(spec);
        ft_putchar(space);
        count++;
    }
}

int             ft_screenprint(int fullscreen)
{
    t_case      *jump;
    int         offset;
    int         line;
    int         col;
    int         row;
    char        *spec;

    jump = ft_screenget_buffer();
    offset = 0;
    line = 1;
    col = ft_screenget_col();
    row = ft_screenget_row();
    while (jump)
    {
        spec = jump->spec;
        if (jump->str[0] == '\n')
        {
            putendl(col - offset, ' ', spec);
            offset = 0;
            line++;
        }
        else
        {
            ft_putstr(jump->str);
            offset++;
        }
        if (offset == col)
        {
            offset = 0;
            line++;
        }
        jump = jump->next;
    }
    while (line <= row && fullscreen == 1)
    {
            putendl(col - offset, '.', spec);
            offset = 0;
            line++;
    }
    return (((line - 1) * col) + offset);
}
