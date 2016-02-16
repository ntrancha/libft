/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:59:52 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 15:57:09 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/list.h"
#include "../../includes/time.h"
#include "../../includes/mem.h"

static void *ft_memcpyvoid(void *src, void *dst)
{
    t_alloc     *alloc;
    void        *mem;
    void        *new;

    alloc = ft_alloc_get(src);
    if (!(mem = ft_memalloc(sizeof(void*) * alloc->size)))
        return (NULL);
    new = ft_memcpy(mem, alloc->content, alloc->size);
    return (ft_alloc_create((void*)new, alloc->size, dst, alloc->type));
}

static int      ft_memcmpvoid(void *a, void *b)
{
    t_alloc     *alloc;

    if (!(alloc = ft_alloc_getvoid(a)))
        return (0);
    return (ft_memcmp((void*)a, (void*)b, alloc->size));
}

void        ft_sysmem(void)
{
    t_type  *type; 

    type = ft_vartype_add("mem", sizeof(void*), ft_memdel); 
    while (type && type->next)
        type = type->next;
    type->cpy = ft_memcpyvoid; 
    type->cmp = ft_memcmpvoid; 
}
