/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:30:08 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/08 14:49:20 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/put.h"

static int      ft_lenint(int cp)
{
    int         nblen;

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

static char     *ft42_itoa(int n)
{
    int         nblen;
    int         sign;
    char        *res;
    t_stacks    *stack;

    if (!(stack = ft_stack_init()))
        return (NULL);    
    sign = (n < 0) ? 1 : 0;
    nblen = ft_lenint(n);
    res = (char *)ft_memalloc(sizeof(char) * (nblen + sign + 1));
    stack->sys += sizeof(char) * (nblen + sign + 1);
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
static void     ft42_putnbr_endl(int n)
{
	char	    *str;

	str = ft42_itoa(n);
	ft_putendl(str);
	ft_strdel(&str);
}

static void     ft_stack_display(void)
{
    t_stacks    *stack;
    t_alloc     *alloc;
    t_type      *type;

    stack = ft_stack_init();
    alloc = stack->alloc;
    while (alloc)
    {
        type = ft_vartype_get(alloc->type);
        if (alloc->name)
            ft_putstr((char *)alloc->name);
        else
            ft_putstr("#");
        ft_putstr(" (");
        if (alloc->type)
            ft_putstr((char *)alloc->type);
        else
            ft_putstr("sys");
        ft_putstr(") : ");
        if (type && alloc->content && type->put)
            type->put(alloc->content);
        ft_putendl("");
        alloc = alloc->next;
    }
}

void            ft_stack_infos(void)
{
    t_stacks    *stack;

    stack = ft_stack_init();
    ft_putendl("===========INFOS===========");
    ft_putstr("allocs               :");
    ft42_putnbr_endl((int)stack->elements + (int)stack->free);
    ft_putstr("actifs               :");
    ft42_putnbr_endl((int)stack->elements);
    ft_putstr("frees                :");
    ft42_putnbr_endl(((int)stack->free));
    ft_putstr("bytes allocated      :");
    ft42_putnbr_endl((int)stack->sys);
    ft_putstr("stack size           :");
    ft42_putnbr_endl((int)stack->stack_size);
    ft_putstr("stack free           :");
    ft42_putnbr_endl((int)stack->stack_free);
    ft_putendl("===========STACK===========");
    ft_stack_display();
    ft_putendl("===========STACK===========");
}
