/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:41:00 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/22 21:11:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

static void ft_func_free(t_funcs *func)
{
    t_funcs *next;

    while (func)
    {
        if (func->name)
            ft_strdel(&(func->name));
        if (func->func_name)
            ft_strdel(&(func->name));
        if (func->func)
            ft_memdel((void**)&func->func);
        next = func->next;
        ft_memdel((void**)&func);
        func = next;
    }
}
void        *ft_vartype_delete(t_type *var)
{
    t_type  *next;

    if (var)
    {
        next = var->next;
        if (var->func)
            ft_func_free(var->func);
        if (var->type)
            ft_strdel(&(var->type));
        ft_memdel((void**)&var);
        ft_vartype_delete(next);
    }
    return (NULL);
}
