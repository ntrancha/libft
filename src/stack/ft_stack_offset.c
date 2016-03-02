/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_offset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:08:38 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/02 23:09:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int             ft_stack_offset(void)
{
    t_stacks    *stack;
    
    stack = ft_stack_init();
    if (stack)
        return (stack->offset);
    return (-1);
}
