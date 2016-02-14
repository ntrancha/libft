/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:33:24 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/14 20:58:10 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/put.h"
#include "../../includes/stack.h"

void	        ft_memdel(void **ap)
{
    #ifdef STACK_H
    t_stacks    *stack;
    #endif

	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
        #ifdef STACK_H
        stack = ft_stack_init();
        if (stack)
           stack->stack_free += 1;
        #endif
	}
}
