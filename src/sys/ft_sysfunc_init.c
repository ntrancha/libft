/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysfunc_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:21:02 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/22 21:13:52 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/stack.h"

static void     ft_tabstrunsort_void(void *ptr)
{
    t_alloc     *alloc;
    char        **tab;

    alloc = (t_alloc*)ptr;
    if (alloc && alloc->type && ft_strcmp(alloc->type, "tabstr") == 0)
    {
        tab = (char**)alloc->content;
        ft_tabstrsort(&tab, -1);
    }
}

static void     ft_tabstrsort_void(void *ptr)
{
    t_alloc     *alloc;
    char        **tab;

    alloc = (t_alloc*)ptr;
    if (alloc && alloc->type && ft_strcmp(alloc->type, "tabstr") == 0)
    {
        tab = (char**)alloc->content;
        ft_tabstrsort(&tab, 1);
    }
}

void            ft_sysfunc_init(void)
{
    ft_sysfunc_add("tabstr", "sort", "vv*", ft_tabstrsort_void);
    ft_sysfunc_add("tabstr", "unsort", "vv*", ft_tabstrunsort_void);
}
