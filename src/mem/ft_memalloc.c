/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:07:30 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/09 09:16:22 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../../includes/mem.h"

void		    *ft_memalloc(size_t size)
{
    #ifdef STACK_H
    t_stacks    *stack;
    #endif
	void	    *ptr;

	if (size == 0)
		return (NULL);
	ptr = malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	ptr = ft_memset(ptr, '\0', size);
    #ifdef STACK_H
       if (!(stack = ft_stack_init()))
       {
            ft_memdel(&ptr);
            return (NULL);
       }
       else
           stack->sys += size;
    #endif
	return (ptr);
}
