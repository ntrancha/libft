/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:18:27 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/13 20:38:47 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void            *ft_calloc(void *var, size_t len, char *id, char *type)
{
    void        *copy;

    if (!(copy = ft_memalloc(len)))
        return (NULL);
    if (!(copy = ft_memcpy(copy, var, len)))
        return (NULL);
    return (ft_alloc_create(copy, len, id, type));
}
