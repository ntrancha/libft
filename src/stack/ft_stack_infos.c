/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:30:08 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 07:41:11 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/count.h"
#include "../../includes/put.h"
#include "../../includes/macros.h"

static void     ft_stack_display(t_alloc *alloc)
{
    ft_putendl("\033[35m============== VARIABLES ===============\033[0m");
    while (alloc)
    {
        if (alloc->name)
            ft_putstr_color((char *)alloc->name, C_YELLOW);
        else
            ft_putstr("#");
        ft_putspace(16 - ft_strlen(alloc->name));
        if (alloc->type)
            ft_putstr_color((char *)alloc->type, C_GREEN);
        else
            ft_putstr_color("sys", C_GREEN);
        ft_putspace(22 - ft_strlen(alloc->type));
        ft_putstr(C_BLUE);
        ft_alloc_put(alloc->name);
        ft_putendl(C_NULL);
        alloc = alloc->next;
    }
    ft_putendl("\033[35m================ STACK =================\033[0m");
    ft_sys_print();
    ft_putendl("\033[35m================ INFOS =================\033[0m");
}

static void     ft_stack_show_test(void *type)
{
    if (type)
        ft_putstr("  X ");
    else
        ft_putstr("    ");
}

static void     ft_stack_convert(t_stacks *stack, t_type *type, t_cnvrt *conv)
{
    int         test;

    while (type)
    {
        ft_putstr_color(type->type, C_GREEN);
        ft_putspace(16 - ft_strlen(type->type));
        conv = stack->convert;
        test = 0;
        while (conv)
        {
            if (ft_strcmp(conv->src, type->type) == 0)
            {
                if (test == 1)
                    ft_putstr(", ");
                ft_putstr_color(conv->dst, C_GREEN);
                test = 1;
            }
            conv = conv->next;
        }
        if (test == 1)
            ft_putstr(".");
        ft_putendl("");
        type = type->next;
    }
    ft_stack_display(stack->alloc);
}

static void     ft_stack_show(t_stacks *stack)
{
    t_type      *type;

    type = stack->types;
    ft_putendl("\033[35m================ TYPES =================\033[0m");
    ft_putendl("           \033[33mdel put cpy cmp fus len count \033[0m");
    while (type)
    {
        if (type->type)
        {
            ft_putstr_color(type->type, C_GREEN);
            ft_putspace(9 - ft_strlen(type->type));
            ft_stack_show_test(type->del);
            ft_stack_show_test(type->put);
            ft_stack_show_test(type->cpy);
            ft_stack_show_test(type->cmp);
            ft_stack_show_test(type->fus);
            ft_stack_show_test(type->len);
            ft_stack_show_test(type->count);
            ft_putstr("\n");
        }
        type = type->next;
    }
    ft_stack_infos_func();
    ft_putendl("\033[35m=============== CONVERT ================\033[0m");
    ft_stack_convert(stack, stack->types, stack->convert);
}

void            ft_stack_infos(void)
{
    t_stacks    *stack;

    stack = ft_stack_init();
    ft_stack_show(stack);
    ft_putstr("allocs\033[32m");
    ft_putspace(33 - ft_nbrlen((int)stack->elements + (int)stack->free));
    ft_putnbr_endl((int)stack->elements + (int)stack->free);
    ft_putstr("\033[0mactifs\033[33m");
    ft_putspace(33 - ft_nbrlen((int)stack->elements));
    ft_putnbr_endl((int)stack->elements);
    ft_putstr("\033[0mfrees\033[31m");
    ft_putspace(34 - ft_nbrlen((int)stack->free));
    ft_putnbr_endl(((int)stack->free));
    ft_putstr("\033[0mbytes allocated\033[32m");
    ft_putspace(24 - ft_nbrlen((int)stack->sys));
    ft_putnbr_endl((int)stack->sys);
    ft_putstr("\033[0mstack alloc\033[33m");
    ft_putspace(28 - ft_nbrlen((int)stack->stack_size));
    ft_putnbr_endl((int)stack->stack_size);
    ft_putstr("\033[0mstack free\033[31m");
    ft_putspace(29 - ft_nbrlen((int)stack->stack_free));
    ft_putnbr_endl((int)stack->stack_free);
    ft_putendl("\033[35m========================================\033[0m");
}
