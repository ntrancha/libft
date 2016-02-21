/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_erase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 13:18:00 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/21 21:27:52 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void        *ft_calloc_erase(void *var, size_t len, char *id, char *type)
{
    if (!ft_stack_init() || !ft_vartype_get(type) || !len)
        return (NULL);
    if (ft_alloc_get(id) != NULL)
        ft_alloc_del(id);
    return (ft_calloc(var, len, id, type));
}
