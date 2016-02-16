/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:54:18 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 10:55:09 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/put.h"
#include "../../includes/mem.h"

static void     *ft_cpyvoid(void *src, void *dest)
{
    t_alloc     *alloc;

    if (!(alloc = ft_alloc_get(src)))
        return (NULL);
    return (ft_alloc_create(ft_strdup(alloc->content), alloc->size, dest, alloc->type));
}

static void     ft_putvoid(void *str)
{
    ft_putstr((char *)str);
}

t_type      *ft_vartype_init(void)
{
    t_type  *new;

    if (!(new = ft_memalloc(sizeof(t_type))))
        return (NULL);
    new->type = ft_strdup("str");
    new->n_octet = sizeof(char);
    new->del = ft_memdel;
    new->put = ft_putvoid;
    new->cpy = ft_cpyvoid;
    return (new);
}
