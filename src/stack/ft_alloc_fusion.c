/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_fusion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:18:04 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 20:34:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void    *ft_alloc_fusion(char *one, char *two, char *new)
{
    t_alloc *alloc_one;
    t_alloc *alloc_two;
    t_type  *type;

    alloc_one = ft_alloc_get(one);
    alloc_two = ft_alloc_get(two);
    type = ft_vartype_get(alloc_one->type);
    if (!alloc_one || !alloc_two || !type)
        return (NULL);
    if (ft_strcmp(alloc_one->type, alloc_two->type) != 0)
        return (NULL);
    return (type->fus(alloc_one->content, alloc_two->content, new));
}
