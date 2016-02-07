/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:33:41 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 00:35:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/count.h"

int      ft_stack_size(void)
{
    t_stacks    *stack;
    t_alloc     *alloc;
    int         size;

    stack = ft_stack_init();
    alloc = stack->alloc;
    size = 0;
    while (alloc)
    {
        size += ft_strlen(alloc->name) + ft_strlen(alloc->type);
        alloc = alloc->next;
    }
    return (size);
}
