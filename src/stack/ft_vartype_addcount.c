/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_addcount.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 13:24:50 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 13:25:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_type      *ft_vartype_addcount(char *type, int (*count)(void*))
{
    t_type  *node;
    t_stacks  *stack;

    stack = ft_stack_init();
    if (!type || !count || ft_vartype_get(type) != NULL)
        return (NULL);
    node = stack->types;
    while (node && node->next)
        node = node->next;
    node->count = count;
    return (stack->types);
}
