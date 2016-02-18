/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysstr_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:10:58 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 09:10:09 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/stack.h"
#include "../../includes/convert.h"

void        ft_sysstr_to_int(void *src, char *dst)
{
    char    *old;
    char    *tmp;

    if (src && ft_strcmp(dst, "int") == 0)
    {
        old = ft_strdup(((t_alloc*)src)->name);
        ft_sysint_alloc(ft_atoi((char*)((t_alloc*)src)->content), old);
        ft_strdel(&old);
    }
    if (src && ft_strcmp(dst, "str") == 0)
    {
        old = ft_strdup(((t_alloc*)src)->name);
        tmp = ft_itoa((int)*((int*)((t_alloc*)src)->content));
        ft_alloc_erase(tmp, ((t_alloc*)src)->size, old, dst);
        ft_strdel(&old);
    }
}

void        ft_sysstr_convert(void)
{
    ft_alloc_cnvrt_add("str", "int", ft_sysstr_to_int);
    ft_alloc_cnvrt_add("int", "str", ft_sysstr_to_int);
}
