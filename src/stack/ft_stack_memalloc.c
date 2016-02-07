/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_memalloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:07:51 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 01:08:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void            *ft_stack_memalloc(size_t size)
{
    void        *ptr;
    t_stacks    *stack;

    ptr = ft_memalloc(size);
    stack = ft_stack_init();
    stack->sys += size;
    return (ptr);
}
