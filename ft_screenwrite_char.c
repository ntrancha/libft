/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenwrite_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:33:01 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/01 01:10:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int             ft_screenwrite_char(char c, char *spec)
{
    char        *str;
    t_screen    *screen;

    screen = ft_screeninit();
    if (!screen)
        return (-1);
    str = ft_strnew(2);
    if (!str)
        return (-1);
    str[0] = c;
    str[1] = '\0';
    if (screen->cursor < screen->size)
        ft_caseset(screen->original, screen->cursor, str, spec);
    else if (screen->size++ > -1)
        screen->original = ft_caseadd(screen->original, str, spec);
    ft_strdel(&str);
    screen->cursor++;
    return (1);
}
