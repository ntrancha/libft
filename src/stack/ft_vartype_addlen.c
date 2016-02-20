/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_addlen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 13:23:50 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 13:24:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_type      *ft_vartype_addlen(char *type, int (len)(void*))
{
    t_type  *node;
    t_stacks  *stack;

    stack = ft_stack_init();
    if (!type || !len || ft_vartype_get(type) != NULL)
        return (NULL);
    node = stack->types;
    while (node && node->next)
        node = node->next;
    node->len = len;
    return (stack->types);
}
