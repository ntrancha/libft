/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenwrite_charl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 03:45:16 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:16:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"

int     ft_screenwrite_charl(int line, char c, char *spec)
{
    int count;
    int ret;

    count = 0;
    ret = 0;
    if (line < 1 || ft_screenset_lcursor(0, line) == -1)
        return (-1);
    while (count++ < ft_screenget_col())
        ret += ft_screenwrite_char(c, spec);
    return (ret);
}
