/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:42:29 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/14 12:01:22 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_type      *ft_vartype_add(char *type, size_t n, void (*del)(void**))
{
    t_type  *new;
    t_type  *node;
    t_stacks  *stack;

    stack = ft_stack_init();
    if (!type || !del || ft_vartype_get(type) != NULL)
        return (NULL);
    if (!(new = ft_memalloc(sizeof(t_type))))
        return (NULL);
    if (!(new->type = ft_strdup(type)))
        return (NULL);
    new->n_octet = n;
    new->del = del;
    new->put = NULL;
    new->cpy = NULL;
    new->next = NULL;
    if (!(node = stack->types->next))
        stack->types->next = new;
    else
    {
        while (node->next)
            node = node->next;
        node->next = new;
    }
    return (stack->types);
}
