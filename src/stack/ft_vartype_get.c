/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:59:01 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 01:23:13 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"

t_type      *ft_vartype_get(char *type)
{
    t_stacks    *stack;
    t_type      *var;

    stack = ft_stack_init();
    var = stack->types;
    if (!var)
        return (NULL);
    while (type && var)
    {
        if (var->type && ft_strcmp(var->type, type) == 0)
            return (var);
        var = var->next;
    }
    return (NULL);
}
