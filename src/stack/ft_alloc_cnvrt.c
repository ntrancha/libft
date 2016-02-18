/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_cnvrt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:30:21 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 08:39:07 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/macros.h"
#include "../../includes/strings.h"

static t_cnvrt  *ft_find_convert(t_stacks *stack, char *src, char *dst)
{
    t_cnvrt     *convert;

    convert = stack->convert;
    while (convert)
    {
        if (CMP(convert->src, src) == 0 && CMP(convert->dst, dst) == 0)
            return (convert);
        convert = convert->next;
    }
    return (NULL);
}


void            ft_alloc_cnvrt(char *src, char *type)
{
    t_stacks    *stack;
    t_alloc     *alloc;
    t_cnvrt     *cnvrt;

    if ((stack = ft_stack_init()))
        if ((alloc = ft_alloc_get(src)))
            if ((cnvrt = ft_find_convert(stack, alloc->type, type)))
                cnvrt->cnvrt(alloc, type);
}
