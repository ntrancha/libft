/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:38:28 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 15:44:29 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int         ft_alloc_cmp(char *a, char *b)
{
    t_alloc *alloc_a;
    t_alloc *alloc_b;
    t_type  *type;

    alloc_a = ft_alloc_get(a);
    alloc_b = ft_alloc_get(b);
    if (alloc_a && alloc_b && alloc_a->type && alloc_b->type)
        if (ft_strcmp(alloc_a->type, alloc_b->type) == 0)
        {
            type = ft_vartype_get(alloc_a->type);
            if (alloc_b->content && type && type->cmp && alloc_a->content)
                return (type->cmp(alloc_a->content, alloc_b->content));
        }
    return (0);
}
