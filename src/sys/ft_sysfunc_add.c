/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysfunc_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:28:45 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/24 01:45:42 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/mem.h"

static int      ft_sysfunc_union(char *func)
{
    if (ft_strcmp(func, "v*v*") == 0)
        return (1);
    if (ft_strcmp(func, "v*v*v*") == 0)
        return (2);
    if (ft_strcmp(func, "v*v*v*v*") == 0)
        return (3);
    if (ft_strcmp(func, "vv*") == 0)
        return (4);
    if (ft_strcmp(func, "vv*v*") == 0)
        return (5);
    if (ft_strcmp(func, "vv*v*v*") == 0)
        return (6);
    if (ft_strcmp(func, "iv*") == 0)
        return (7);
    if (ft_strcmp(func, "iv*v*") == 0)
        return (8);
    if (ft_strcmp(func, "iv*v*v*") == 0)
        return (9);
    return (0);
}

static void     add_func(t_func *func_ptr, void *fptr, int function)
{
    if (function == 1)
        func_ptr->f_voidp_a = fptr;
    if (function == 2)
        func_ptr->f_voidp_b = fptr;
    if (function == 3)
        func_ptr->f_voidp_c = fptr;
    if (function == 4)
        func_ptr->f_void_a = fptr;
    if (function == 5)
        func_ptr->f_void_b = fptr;
    if (function == 6)
        func_ptr->f_void_c = fptr;
    if (function == 7)
        func_ptr->f_int_a = fptr;
    if (function == 8)
        func_ptr->f_int_b = fptr;
    if (function == 9)
        func_ptr->f_int_c = fptr;
}

static t_funcs  *func_create(char *name, char *func, void *fptr)
{
    t_funcs     *new;
    t_func      *func_ptr;
    int         function;

    if (!(new = ft_memalloc(sizeof(t_funcs))))
        return (NULL);
    if (!(func_ptr = ft_memalloc(sizeof(t_func))))
        return (NULL);
    new->name = ft_strdup(name);
    new->func_name = ft_strdup(func);
    new->func = func_ptr;
    new->next = NULL;
    function = ft_sysfunc_union(func);
    add_func(func_ptr, fptr, function);
    return (new);
}

void            *ft_sysfunc_add(char *add, char *name, char *func, void *fptr)
{
    t_stacks    *stack;
    t_type      *type;
    t_funcs     *funcs;
    t_funcs     *new;

    if (!(stack = ft_stack_init()))
        return (NULL);
    if (!(type = ft_vartype_get(add)))
        return (NULL);
    funcs = type->func;
    if (ft_sysfunc_exist(funcs, name))
        return (NULL);
    if (!(ft_sysfunc_union(func)))
        return (NULL);
    if (!(new = func_create(name, func, fptr)))
        return (NULL);
    if (!funcs)
        type->func = new;
    else
    {
        while (funcs && funcs->next)
            funcs = funcs->next;
        funcs->next = new;
    }
    return (new);
}
