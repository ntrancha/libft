/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_memalloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:07:51 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/08 23:06:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/mem.h"

void            *ft_stack_memalloc(size_t size)
{
    void        *ptr;
    t_stacks    *stack;

    if (!(ptr = ft_memalloc(size)))
        return (NULL);
    if (!(stack = ft_stack_init()))
    {
        ft_memdel(&ptr);
        return (NULL);
    }
    stack->sys += size;
    return (ptr);
}
