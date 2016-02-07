/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_rename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:27:07 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 01:27:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"

t_stacks        *ft_alloc_rename(char *id, char *new_name)
{
    t_stacks    *stack;
    t_alloc     *alloc;

    if (!(stack = ft_stack_init()) || !stack->alloc)
        return (NULL);    
    alloc = stack->alloc;
    while (alloc)
    {
        if (!ft_strcmp(alloc->name, id))
        {
            ft_strdel(&(alloc->name));
            alloc->name = ft_strdup(new_name);
            return (stack);
        }
        alloc = alloc->next;
    }
    return (NULL);
}
