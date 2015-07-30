/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenwrite_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:33:01 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 06:38:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int             ft_screenwrite_char(char c, char *spec)
{
    char        *str;
    t_screen    *screen;

    str = ft_strnew(2);
    if (!str)
        return (-1);
    str[0] = c;
    str[1] = '\0';
    screen = ft_screeninit();
    if (!screen)
        return (-1);
    screen->buffer = ft_caseadd(screen->buffer, str, spec);
    if (!screen->buffer)
        return (-1);
    screen->size++;
    screen->offset++;
    return (1);
}
