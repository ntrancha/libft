/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_addfus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 13:22:29 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 13:23:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_type      *ft_vartype_addfus(char *type, void *(*fus)(void*, void*, char*))
{
    t_type  *node;
    t_stacks  *stack;

    stack = ft_stack_init();
    if (!type || !fus || ft_vartype_get(type) != NULL)
        return (NULL);
    node = stack->types;
    while (node && node->next)
        node = node->next;
    node->fus = fus;
    return (stack->types);
}
