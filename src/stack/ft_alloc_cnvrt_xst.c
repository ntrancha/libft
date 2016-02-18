/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_cnvrt_xst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 07:52:45 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 08:01:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/macros.h"
#include "../../includes/strings.h"

int             ft_alloc_cnvrt_xst(char *src, char *dst)
{
    t_stacks    *stack;
    t_cnvrt     *convert;

    stack = ft_stack_init();
    convert = stack->convert;
    while (convert)
    {
        if (CMP(src, convert->src) == 0 && CMP(dst, convert->dst) == 0)
            return (1);
        convert = convert->next;
    }
    return (0);
}
