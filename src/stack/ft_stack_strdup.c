/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:07:00 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 01:07:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/count.h"

void            *ft_stack_strdup(char *str)
{
    void        *ptr;
    t_stacks    *stack;

    ptr = ft_strdup(str);
    stack = ft_stack_init();
    stack->sys += ft_strlen(str) * sizeof(char);
    return (ptr);
}
