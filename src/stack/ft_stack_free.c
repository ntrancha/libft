/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:28:08 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 01:43:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/mem.h"

static void     ft_vartype_free(void)
{
    t_stacks    *stack;

    stack = ft_stack_init();
    ft_vartype_delete(stack->types);
}

void            *ft_stack_free(void)
{
    t_stacks    *stack;

    stack = ft_stack_init();
    if (!stack)
        return (NULL);
    ft_stack_clean();
    ft_vartype_free();
    ft_memdel((void**)&stack);
    return (NULL);
}
