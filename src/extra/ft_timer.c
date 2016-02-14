/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 23:34:10 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/14 23:49:02 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/extra.h"

static void ft_time_sleep(int ns)
{
    while (ns > 0)
        ns--;
}

void        ft_timer(int ms)
{
    ms *= 10;
    while (--ms > 0)
        ft_time_sleep(SYSTIMER);
}
