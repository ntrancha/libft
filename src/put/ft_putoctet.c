/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:59:20 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/11 18:13:15 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/convert.h"
#include "../../includes/put.h"
#include "../../includes/bits.h"
#include "../../includes/strings.h"

void        ft_putoctet(t_octet octet)
{
    char    *ret;
    char    *tmp;

    ret = ft_itoa(ft_dectobin((int)octet));
    while ((int)ft_strlen(ret) < 8)
    {
        tmp = ft_strjoin("0", ret);
        ft_strdel(&ret);
        ret = tmp;
    }
    ft_putstr(ret);
    ft_strdel(&ret);
}
