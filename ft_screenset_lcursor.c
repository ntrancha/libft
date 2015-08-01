/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenset_lcursor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 02:35:26 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/01 02:40:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int     ft_screenset_lcursor(int col, int row)
{
    int screen_col;

    screen_col = ft_screenget_col();
    if (screen_col == -1)
        return (-1);
    return (ft_screenset_cursor(((row - 1) * screen_col) + col));
}

