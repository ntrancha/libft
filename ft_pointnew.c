/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:05:48 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/15 14:05:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

t_point     *ft_pointnew(int x, int y, int z)
{
    t_point *p;

    p = malloc(sizeof(t_point));
    if (p == NULL)
        return (NULL);
    p->x = x;
    p->y = y;
    p->z = z;
    return (p);
}
