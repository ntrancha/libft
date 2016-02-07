/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:54:18 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 01:13:19 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

static void     *ft_cpyvoid(void *src, void *dest)
{
    t_alloc     *alloc;

    alloc = ft_alloc_get(src);
    return (ft_alloc(alloc->content, alloc->size, dest, alloc->type));
}

static void     ft_putvoid(void *str)
{
    ft_putstr((char *)str);
}

t_type      *ft_vartype_init(void)
{
    t_type  *new;

    if (!(new = ft_stack_memalloc(sizeof(t_type))))
        return (NULL);
    new->type = ft_stack_strdup("str");
    new->n_octet = sizeof(char);
    new->del = ft_memdel;
    new->put = ft_putvoid;
    new->cpy = ft_cpyvoid;
    new->next = NULL;
    return (new);
}
