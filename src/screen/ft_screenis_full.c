/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenis_full.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 02:02:54 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:13:31 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"

int         ft_screenis_full(void)
{
    int     size;
    int     row;
    int     col;

    size = ft_screenget_size();
    col = ft_screenget_col();
    row = ft_screenget_row();
    if (size >= (col * row))
        return (1);
    return (0);
}
