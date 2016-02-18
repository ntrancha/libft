/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_convert_add.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 07:37:05 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 08:07:56 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/mem.h"

static t_cnvrt  *ft_cnvrt_end(t_stacks *stack, t_cnvrt *cnvrt)
{
    t_cnvrt     *convert;

    convert = stack->convert;
    while (convert && convert->next)
        convert = convert->next;
    if (convert)
        convert->next = cnvrt;
    return (convert);
}

t_cnvrt         *ft_alloc_cnvrt_add(char *s, char *d, void (*c)(void*, char*))
{
    t_stacks    *stack;
    t_type      *type_src;
    t_type      *type_dst;
    t_cnvrt     *new;

    if (!s || !d || !c)
        return (NULL);
    type_src = ft_vartype_get(s);
    type_dst = ft_vartype_get(d);
    stack = ft_stack_init();
    if (!type_src || !type_dst || !stack)
        return (NULL);
    if (ft_alloc_cnvrt_xst(s, d))
        return (NULL);
    new = ft_memalloc(sizeof(t_cnvrt));
    new->src = ft_strdup(s);
    new->dst = ft_strdup(d);
    new->cnvrt = c;
    if (!stack->convert)
        stack->convert = new;
    else
        ft_cnvrt_end(stack, new);
    return (new);
}
