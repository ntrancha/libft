/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointcreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 11:26:40 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/06 11:29:01 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/math.h"
#include "../../includes/mem.h"

t_point     *ft_pointcreate(int x, int y)
{
    t_point *point;

    point = ft_memalloc(sizeof(t_point));
    if (!point)
        return (NULL);
    point->x = x;
    point->y = y;
    return (point);
}
