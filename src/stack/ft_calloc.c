/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:18:27 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 17:29:33 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

static int  ft_lenint(int cp)
{
    int     nblen;

    if (cp == 0)
        return (1);
    nblen = 0;
    while (cp != 0)
    {
        nblen++;
        cp = cp / 10;
    }
    return (nblen);
}

static char *itoa(int n)
{
    int     nblen;
    int     sign;
    char    *res;

    sign = (n < 0) ? 1 : 0;
    nblen = ft_lenint(n);
    res = NULL;
    res = (char *)ft_malloc(sizeof(char) * (nblen + sign + 1));
    if (res)
    {
        res = res + nblen + sign;
        *res = '\0';
        if (!n)
            *--res = '0';
        while (n != 0)
        {
            *--res = ft_abs(n % 10) + '0';
            n = n / 10;
        }
        if (sign)
            *--res = '-';
    }
    return (res);
}

static char     *ft_stack_randomid(void)
{
    static int  id_rand;

    id_rand++;
    return (itoa(id_rand));
}

static void     ft_alloc_more(char *type, t_stacks *stack, size_t len)
{
    t_type      *types;

    types = ft_vartype_get(type);
    stack->elements += 1;
    stack->stack_size += (len * types->n_octet);
}

void            *ft_calloc(void *var, size_t len, char *id, char *type)
{
    t_alloc     *alloc;
    t_alloc     *new;
    t_stacks    *stack;

    if (!var || !(stack = ft_stack_init()) || !ft_vartype_get(type))
        return (NULL);    
    alloc = stack->alloc;
    while (alloc && alloc->next)
        alloc = alloc->next;
    if (!(new = ft_stack_memalloc(sizeof(t_alloc))))
        return (NULL);
    new->content = var;
    new->size = len;
    new->name = (id) ? ft_stack_strdup(id) : ft_stack_randomid();
    new->type = ft_vartype_gettype(type);
    new->next = NULL;
    ft_alloc_more(type, stack, len);
    if (stack->alloc == NULL)
        stack->alloc = new;
    else
        alloc->next = new;
    return (new->content);
}
