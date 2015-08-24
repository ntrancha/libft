/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenset_cursor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:22:58 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:14:06 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"

int             ft_screenset_cursor(int cursor)
{
    t_screen    *screen;

    screen = ft_screeninit();
    if (!screen || cursor < 0)
        return (-1);
    screen->cursor = cursor;
    return (cursor);
}
