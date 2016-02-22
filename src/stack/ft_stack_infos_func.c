/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_infos_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:11:28 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/22 21:17:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/count.h"
#include "../../includes/put.h"
#include "../../includes/macros.h"

static void     func_type_return(char c)
{
    if (c == 'v')
        ft_putstr_color("void    ", C_GREEN);
    else if (c == 'i')
        ft_putstr_color("int     ", C_GREEN);
}

static void     func_type_args(char *c)
{
    int         count;
    int         test;

    count = 1;
    ft_putchar('(');
    if (c[count] == '*')
        count++;
    test = 0;
    while (c[count])
    {
        if (test && c[count] != '*')
            ft_putstr(", ");
        else 
            test = 1;
        if (c[count] == 'v')
            ft_putstr_color("void", C_GREEN);
        if (c[count] == '*')
            ft_putchar('*');
        count++;
    }
    ft_putendl(")");
}

void            ft_stack_infos_func(void)
{
    t_stacks    *stacks;
    t_type      *types;
    t_funcs     *funcs;

    ft_putendl("\033[35m============== FUNCTIONS ===============\033[0m");
    stacks = ft_stack_init();
    types = stacks->types;
    while (types)
    {
        funcs = types->func;
        while (funcs)
        {
            ft_putstr_color(types->type, C_GREEN);
            ft_putspace(16 - ft_strlen(types->type));
            func_type_return(funcs->func_name[0]);
            ft_putspace(14);
            if (funcs->func_name[1] == 42)
                ft_putchar('*');
            ft_putstr(funcs->name);
            func_type_args(funcs->func_name);
            funcs = funcs->next;
        }
        types = types->next;
    }
}
