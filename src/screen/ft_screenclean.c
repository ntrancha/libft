/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenclean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:31:12 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:08:52 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"
#include "../../includes/strings.h"
#include "../../includes/put.h"

void            ft_screenclean(void)
{
    int         count;

    count = 0;
    while (count++ <= ft_screenget_size())
        ft_putchar('\b');
    while (count-- >= 0)
        ft_putchar(' ');
    while (count++ <= ft_screenget_size())
        ft_putchar('\b');
    ft_screenset_cursor(0);
    ft_screenset_size(0);
}
