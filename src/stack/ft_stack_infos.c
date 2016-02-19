/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:30:08 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 10:12:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/count.h"
#include "../../includes/put.h"

static void     ft_stack_display(void)
{
    t_stacks    *stack;
    t_alloc     *alloc;

    stack = ft_stack_init();
    alloc = stack->alloc;
    while (alloc)
    {
        if (alloc->name)
            ft_putstr((char *)alloc->name);
        else
            ft_putstr("#");
        ft_putspace(16 - ft_strlen(alloc->name));
        if (alloc->type)
            ft_putstr((char *)alloc->type);
        else
            ft_putstr("sys");
        ft_putspace(13 - ft_strlen(alloc->type));
        ft_putstr(": ");
        ft_alloc_put(alloc->name);
        ft_putendl("");
        alloc = alloc->next;
    }
}

static void     ft_stack_show_test(void *type)
{
    if (type)
        ft_putstr("  X ");
    else
        ft_putstr("    ");
}

static void     ft_stack_show(t_stacks *stack)
{
    t_type      *type;

    type = stack->types;
    ft_putendl("             [ del put cpy cmp len count ]");
    while (type)
    {
        if (type->type)
        {
            ft_putstr(type->type);
            ft_putspace(13 - ft_strlen(type->type));
            ft_stack_show_test(type->del);
            ft_stack_show_test(type->put);
            ft_stack_show_test(type->cpy);
            ft_stack_show_test(type->cmp);
            ft_stack_show_test(type->len);
            ft_stack_show_test(type->count);
            ft_putstr("\n");
        }
        type = type->next;
    }
}

static void     ft_stack_convert(void)
{
    t_stacks    *stack;
    t_cnvrt     *convert;

    stack = ft_stack_init();
    convert = stack->convert;
    while (convert)
    {
        ft_putstr(convert->src);
        ft_putspace(16 - ft_strlen(convert->src));
        ft_putstr("=>");
        ft_putspace(16 - ft_strlen(convert->dst));
        ft_putendl(convert->dst);
        convert = convert->next;
    }
}

void            ft_stack_infos(void)
{
    t_stacks    *stack;

    stack = ft_stack_init();
    ft_putendl("================== TYPES ==================");
    ft_stack_show(stack);
    ft_putendl("================= CONVERT =================");
    ft_stack_convert();
    ft_putendl("================== STACK ==================");
    ft_stack_display();
    ft_putendl("================== INFOS ==================");
    ft_putstr("allocs                         : ");
    ft_putnbr_endl((int)stack->elements + (int)stack->free);
    ft_putstr("actifs                         : ");
    ft_putnbr_endl((int)stack->elements);
    ft_putstr("frees                          : ");
    ft_putnbr_endl(((int)stack->free));
    ft_putstr("bytes allocated                : ");
    ft_putnbr_endl((int)stack->sys);
    ft_putstr("stack alloc                    : ");
    ft_putnbr_endl((int)stack->stack_size);
    ft_putstr("stack free                     : ");
    ft_putnbr_endl((int)stack->stack_free);
    ft_putendl("===========================================");
}
