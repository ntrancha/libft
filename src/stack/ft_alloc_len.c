/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:56:14 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/23 19:57:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int         ft_alloc_len(char *a)
{
    t_alloc *alloc_a;
    t_type  *type;

    alloc_a = ft_alloc_get(a);
    if (alloc_a && alloc_a->type)
    {
        type = ft_vartype_get(alloc_a->type);
        if (type && type->len && alloc_a->content)
            return (type->len(alloc_a->content));
    }
    return (0);
}
