/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syslist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 00:13:42 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 15:12:52 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/list.h"
#include "../../includes/time.h"
#include "../../includes/mem.h"

static void ft_listdelvoid(void **list)
{
    ft_listdel((t_list**)list, ft_memdel);
}

static void ft_listputstrvoid(void *list)
{
    char    *str;

    str = ft_listtostrd((t_list*)list, "\n");
    ft_putendl(str);
    ft_strdel(&str);
}

static void *ft_listcpyvoid(void *list, void *name)
{
    t_alloc *alloc;
    t_list  *new;

    alloc = ft_alloc_get(list);
    new = ft_liststrcpy((t_list*)alloc->content);
    return (ft_alloc((void*)new, ft_liststrlen(new), name, "liststr"));
}

void        ft_syslist(void)
{
    t_type  *type; 

    type = ft_vartype_add("liststr", sizeof(t_list), ft_listdelvoid); 
    while (type && type->next)
        type = type->next;
    type->put = ft_listputstrvoid; 
    type->cpy = ft_listcpyvoid; 
}
