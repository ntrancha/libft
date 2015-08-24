/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenwrite_charf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:33:01 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:16:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"
#include "../../includes/strings.h"

int             ft_screenwrite_charf(char c, char *spec)
{
    char        *str;
    t_screen    *screen;

    screen = ft_screeninit();
    if (!screen)
        return (-1);
    if (!(str = ft_strnew(2)))
        return (-1);
    str[0] = c;
    str[1] = '\0';
    if (screen->cursor < screen->size)
        ft_caseset(screen->original, screen->cursor, str, spec);
    else if (screen->cursor == screen->size && screen->size++ > -1)
    {
        if (screen->cursor < screen->col * screen->row)
            screen->original = ft_caseadd(screen->original, str, spec);
    }
    else
    {
        ft_strdel(&str);
        return (-1);
    }
    ft_strdel(&str);
    screen->cursor++;
    return (1);
}
