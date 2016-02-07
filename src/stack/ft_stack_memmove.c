/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_memmove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:09:54 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 01:11:00 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void            *ft_stack_memmove(void *dst, void *src, size_t len)
{
    void        *ptr;
    t_stacks    *stack;

    ptr = ft_memmove(dst, src, len);
    stack = ft_stack_init();
    stack->sys += len;
    return (ptr);
}
