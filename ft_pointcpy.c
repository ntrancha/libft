/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:07:04 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/15 14:07:04 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

t_point     *ft_pointcpy(t_point *p)
{
    t_point *cpy;

    cpy = malloc(sizeof(t_point));
    if (cpy == NULL)
        return (NULL);
    cpy->x = p->x;
    cpy->y = p->y;
    cpy->z = p->z;
    cpy->cx = p->cx;
    cpy->cy = p->cy;
    return (cpy);
}
