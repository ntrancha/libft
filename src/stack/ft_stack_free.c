/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:28:08 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/22 21:07:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/stack.h"
#include "../../includes/mem.h"

static void     ft_convert_free(void)
{
    t_stacks    *stack;
    t_cnvrt     *convert;
    t_cnvrt     *next;

    stack = ft_stack_init();
    convert = stack->convert;
    while (convert)
    {
        next = convert->next;
        ft_strdel(&(convert->src));
        ft_strdel(&(convert->dst));
        ft_memdel((void**)&convert);
        convert = next;
    }
}

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
    ft_convert_free();
    free(stack);
    return (NULL);
}
