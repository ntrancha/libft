/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:11:08 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/17 13:38:07 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void        ft_alloc_put(char *id)
{
    t_alloc *alloc;
    t_type      *type;

    alloc = ft_alloc_get(id);
    if (alloc && alloc->type)
        type = ft_vartype_get(alloc->type);
    if (alloc && alloc->content && type && type->put)
        type->put(alloc->content);
}
