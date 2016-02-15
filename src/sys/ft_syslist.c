/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syslist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 00:13:42 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 00:25:24 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/list.h"
#include "../../includes/mem.h"

static void ft_listdelvoid(void **list)
{
    ft_listdel((t_list**)list, ft_memdel);
}

static void ft_listputstrvoid(void *list)
{
    char    *str;

    str = ft_listtostrd(list, "\n");
    ft_putendl(str);
    ft_strdel(&str);
}

static void *ft_listcpyvoid(void *list, void *name)
{
    t_list  *new;

    new = ft_liststrcpy(list);
    return (ft_alloc(new, ft_liststrlen(new), name, "list_str"));
}

void    ft_syslist(void)
{
    ft_vartype_add("list_str", sizeof(t_list), ft_listdelvoid); 
    ft_vartype_addcpy("list_str", ft_listcpyvoid); 
    ft_vartype_addput("list_str", ft_listputstrvoid); 
}
