/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:54:18 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/08 19:44:44 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/put.h"
#include "../../includes/mem.h"

static void     *ft_cpyvoid(void *src, void *dest)
{
    t_alloc     *alloc;

    alloc = ft_alloc_get(src);
    return (ft_alloc(alloc->content, alloc->size, dest, alloc->type));
}

static void     ft_tabstrdelvoid(void **str)
{
    ft_tabstrdel((char **)str);
}

static void     ft_puttabstrvoid(void *str)
{
    int         index;
    char        **tmp;

    index = -1;
    tmp = (char**)str;
    while (tmp[++index])
        ft_putendl(tmp[index]);
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
    if (!(new->next = ft_stack_memalloc(sizeof(t_type))))
        return (NULL);
    new->next->type = ft_stack_strdup("tabstr");
    new->next->del = ft_tabstrdelvoid;
    new->next->put = ft_puttabstrvoid;
    new->next->n_octet = sizeof(char);
    new->next->next = NULL;
    return (new);
}
