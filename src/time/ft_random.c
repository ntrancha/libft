/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 01:40:52 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/15 10:40:22 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/time.h"
#include "../../includes/put.h"
#include "../../includes/convert.h"
#include "../../includes/strings.h"


long    ft_power_long(long nbr, long power)
{
    int ret;

    ret = nbr;
    while (--power)
        ret *= nbr;
    return (ret);
}

int     ft_random(void)
{
    static long mem;

    if (!mem)
        mem = ft_time();
    mem = 16807 * mem % (ft_power_long(2,31) - 1);
    return ((int)mem);
}
