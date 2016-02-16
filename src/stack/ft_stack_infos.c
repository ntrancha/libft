/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:30:08 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 11:16:13 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/count.h"
#include "../../includes/put.h"

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

void            ft_stack_show(t_stacks *stack)
{
    t_type      *type;

    type = stack->types;
    ft_putendl("===========TYPES===========");
    ft_putendl("            [ del put cpy ]");
    while (type)
    {
        if (type->type)
        {
            ft_putstr(type->type);
            ft_putspace(11 - ft_strlen(type->type));
            if (type->del)
                ft_putstr("   X ");
            else
                ft_putstr("     ");
            if (type->put)
                ft_putstr("  X ");
            else
                ft_putstr("    ");
            if (type->cpy)
                ft_putstr("  X ");
            else
                ft_putstr("    ");
            ft_putstr("\n");
        }
        type= type->next;
    }
}

void            ft_stack_infos(void)
{
    t_stacks    *stack;

    stack = ft_stack_init();
    ft_stack_show(stack);
    ft_putendl("===========INFOS===========");
    ft_putstr("allocs               :");
    ft_putnbr_endl((int)stack->elements + (int)stack->free);
    ft_putstr("actifs               :");
    ft_putnbr_endl((int)stack->elements);
    ft_putstr("frees                :");
    ft_putnbr_endl(((int)stack->free));
    ft_putstr("bytes allocated      :");
    ft_putnbr_endl((int)stack->sys);
    ft_putstr("stack alloc          :");
    ft_putnbr_endl((int)stack->stack_size);
    ft_putstr("stack free           :");
    ft_putnbr_endl((int)stack->stack_free);
    ft_putendl("===========STACK===========");
    ft_stack_display();
    ft_putendl("===========STACK===========");
}
