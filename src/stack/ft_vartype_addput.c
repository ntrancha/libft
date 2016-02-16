/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_addput.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:57:26 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 01:23:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_type      *ft_vartype_addput(char *type, void (*put)(void*))
{
    t_type  *node;
    t_stacks  *stack;

    stack = ft_stack_init();
    if (!type || !put || ft_vartype_get(type) != NULL)
    {
        ft_putendl("ko");
        return (NULL);
    }
    node = stack->types;
    while (node && node->next)
        node = node->next;
    node->put = put;
    return (stack->types);
}
