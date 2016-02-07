/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_addcpy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:57:49 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 00:58:02 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_type      *ft_vartype_addcpy(char *type, void *(*cpy)(void*,void*))
{
    t_type  *node;
    t_stacks  *stack;

    stack = ft_stack_init();
    if (!type || !cpy || ft_vartype_get(type) != NULL)
        return (NULL);
    node = stack->types;
    while (node && node->next)
        node = node->next;
    node->cpy = cpy;
    return (stack->types);
}
