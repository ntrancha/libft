/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_systabstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:48:37 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 21:07:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/put.h"
#include "../../includes/mem.h"

static void     ft_tabstrdelvoid(void **str)
{
    char        **tab;
    int         index;

    tab = (char**)*str;
    index = -1;
    while (tab[++index])
        ft_strdel(&(tab[index]));
    ft_memdel((void*)&tab);
}

static void     ft_puttabstrvoid(void *str)
{
    int         index;
    char        **tmp;

    index = -1;
    tmp = (char**)str;
    while (tmp[++index] && tmp[index][0])
        if (tmp[index] && tmp[index + 1])
            ft_putendl(tmp[index]);
        else
            ft_putstr(tmp[index]);
}

static void     *ft_tabstrcpyvoid(void *src, void *dst)
{
    t_alloc     *alloc;
    char        **tab;
    char        **new;
    int         len;

    alloc = ft_alloc_get(src);
    tab = (char**)alloc->content;
    new = ft_tabstrcpy(tab);
    len = 0;
    while (new[len])
        len++;
    return (ft_alloc_create((void*)new, len , dst, alloc->type));
}

static int  ft_tablenvoid(void *a)
{
    return ((int)ft_tabstrcount((char**)a));
}

void            ft_systabstr(void)
{
    t_type  *type; 

    type = ft_vartype_add("tabstr", sizeof(char*), ft_tabstrdelvoid); 
    while (type && type->next)
        type = type->next;
    type->put = ft_puttabstrvoid; 
    type->cpy = ft_tabstrcpyvoid; 
    type->count = ft_tablenvoid; 
}
