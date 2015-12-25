/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octet_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 10:22:34 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/25 12:12:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int         ft_octet_add(t_octet *a, t_octet b)
{
    int     ret;
    int     res;

    ret = 0;
    res = *a + b;
    if (res > 255)
    {
        res -= 256;
        ret = 1;
    }
    *a = res;
    return (ret);
}
