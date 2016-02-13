/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:41:35 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/13 20:37:16 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/mem.h"

static int  ft42_lenint(int cp)
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

static char *ft42_itoa(int n)
{
    int     nblen;
    int     sign;
    char    *res;

    sign = (n < 0) ? 1 : 0;
    nblen = ft42_lenint(n);
    res = NULL;
    res = (char *)ft_memalloc(sizeof(char) * (nblen + sign + 1));
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
    return (ft42_itoa(id_rand));
}

void        *ft_alloc_create(void *var, size_t len, char *id, char *type)
{
    t_alloc     *alloc;
    t_alloc     *new;
    t_stacks    *stack;

    if (!(stack = ft_stack_init()) || !ft_vartype_get(type) || !len)
        return (NULL);    
    alloc = stack->alloc;
    while (alloc && alloc->next)
        alloc = alloc->next;
    if (!(new = ft_memalloc(sizeof(t_alloc))))
        return (NULL);
    if (var)
        new->content = var;
    else if (!(new->content = ft_memalloc(len)))
        return (NULL);
    new->size = len;
    new->name = (id) ? ft_strdup(id) : ft_stack_randomid();
    new->type = ft_vartype_gettype(type);
    new->next = NULL;
    stack->elements += 1;
    if (stack->alloc == NULL)
        stack->alloc = new;
    else
        alloc->next = new;
    return (new->content);
}
