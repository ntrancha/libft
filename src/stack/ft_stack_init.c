/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:26:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/24 19:54:41 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/stack.h"

t_stacks            *ft_stack_init(void)
{
    static t_stacks *alloc;

    if (!alloc)
    {
        if (!(alloc = malloc(sizeof(t_stacks))))
            return (NULL);
        alloc->stack_size = 0;
        alloc->stack_free = 0;
        alloc->elements = 0;
        alloc->free = 0;
        alloc->sys = sizeof(t_stacks);
        alloc->alloc = NULL;
        alloc->pile = NULL;
        alloc->convert = NULL;
        alloc->types = ft_vartype_init();
    }
    return (alloc);
}
