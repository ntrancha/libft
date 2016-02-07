/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:22:01 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 01:22:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

static t_type   *ft_alloc_type(char *id)
{
    t_alloc     *alloc;
    t_type      *type;

    if (id && (alloc = ft_alloc_get(id)))
        if (alloc->type && (type = ft_vartype_get(alloc->type)))
            return (type);
    return (NULL);
}

void            *ft_alloc_copy(char *id, char *new)
{
    t_type      *type;

    if (id && (type = ft_alloc_type(id)))
        if (new && type->cpy)
            return (type->cpy(id, new));
    return (NULL);
}
