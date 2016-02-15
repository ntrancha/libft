/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 01:32:54 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/15 01:38:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/time.h"

void        ft_sleep(int sec)
{
    int     start;
    int     end;

    start = ft_time();
    end = start + sec;
    while (start < end)
        start = ft_time();
}
