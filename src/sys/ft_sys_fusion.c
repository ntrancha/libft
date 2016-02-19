/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys_fusion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 19:45:42 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 21:26:00 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/sys.h"

static void *ft_tabstrfusion_void(void *one, void *two, char *dst)
{
    char    **tab;
    int     len;
    int     size;
    int     count;

    len = ft_tabstrcount((char**)one);
    len += ft_tabstrcount((char**)two);
    tab = ft_memalloc(sizeof(char*) * (len + 1));
    if (!tab)
        return (NULL);
    count = 0;
    len = -1;
    size = len;
    while (((char**)one)[++len])
        tab[count++] = ft_strdup(((char**)one)[len]);
    len = -1;
    while (((char**)two)[++len])
        tab[count++] = ft_strdup(((char**)two)[len]);
    tab[count] = '\0';
    return (ft_alloc_create((void*)tab, size, dst, "tabstr"));
}

static void *ft_strfusion_void(void *one, void *two, char *dst)
{
    char    *str;

    str = ft_strjoin((char*)one, (char*)two);
    if (!str)
        return (NULL);
    return (ASTR(str, dst));
}

static void *ft_listfusion_void(void *one, void *two, char *dst)
{
    t_list  *new;

    new = ft_listfusion((t_list*)one, (t_list*)two);
    if (!new)
        return (NULL);
    return (ft_alloc_create((void*)new, sizeof(t_list), dst, "liststr"));
}

void        ft_sys_fusion(void)
{
    t_type  *type;

    type = ft_vartype_get("liststr");
    type->fus = ft_listfusion_void;
    type = ft_vartype_get("ft_opt");
    type->fus = ft_listfusion_void;
    type = ft_vartype_get("str");
    type->fus = ft_strfusion_void;
    type = ft_vartype_get("tabstr");
    type->fus = ft_tabstrfusion_void;
}
