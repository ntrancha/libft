/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:54:18 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/22 00:23:19 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/put.h"
#include "../../includes/mem.h"
#define SIZE    alloc->size
#define TYPE    alloc->type
#define VAR     alloc->content

static void     *ft_cpyvoid(void *src, void *dest)
{
    t_alloc     *alloc;

    if (!(alloc = ft_alloc_get(src)))
        return (NULL);
    return (ft_alloc_create(ft_strdup(VAR), SIZE, dest, TYPE));
}

static void     ft_putvoid(void *str)
{
    ft_putstr((char *)str);
}

static int      ft_cmpvoid(void *a, void *b)
{
    return (ft_strcmp((char*)a, (char*)b));
}

static int      ft_strlenvoid(void *a)
{
    return ((int)ft_strlen((char*)a));
}

t_type          *ft_vartype_init(void)
{
    t_type      *new;

    if (!(new = ft_memalloc(sizeof(t_type))))
        return (NULL);
    new->type = ft_strdup("str");
    new->n_octet = sizeof(char);
    new->del = ft_memdel;
    new->put = ft_putvoid;
    new->cpy = ft_cpyvoid;
    new->cmp = ft_cmpvoid;
    new->len = ft_strlenvoid;
    new->fus = NULL;
    new->count = NULL;
    new->func = NULL;
    return (new);
}
