/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_addcmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 13:21:04 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 13:22:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_type      *ft_vartype_addcmp(char *type, int (*cmp)(void*,void*))
{
    t_type  *node;
    t_stacks  *stack;

    stack = ft_stack_init();
    if (!type || !cmp || ft_vartype_get(type) != NULL)
        return (NULL);
    node = stack->types;
    while (node && node->next)
        node = node->next;
    node->cmp = cmp;
    return (stack->types);
}
