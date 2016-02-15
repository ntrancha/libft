/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 01:40:52 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/15 02:17:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/time.h"
#include "../../includes/convert.h"
#include "../../includes/strings.h"

int     ft_random(void)
{
    static int  mem;
    char        *tmp;
    char        *tmp2;
    int         len;
    int         ret;

    if (!mem)
        mem = ft_time();
    mem *= mem;
    /*ft_putnbr_endl(mem);*/
    tmp = ft_itoa(mem);
    len = (ft_strlen(tmp) - 4) / 2;
    tmp2 = ft_strsub(tmp, len, 4);
    mem = ft_atoi(tmp2);
    ft_strdel(&tmp2);
    tmp2 = ft_strsub(tmp, len, 1);
    mem += 3;
    ret = ft_atoi(tmp2);
    ft_strdel(&tmp2);
    ft_strdel(&tmp);
    return (ret);
}
