/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysstr_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:10:58 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 08:29:00 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/stack.h"

void        ft_sysstr_to_int(void *src, char *dst)
{
    char    *old;

    if (src && ft_strcmp(dst, "int") == 0)
    {
        old = ft_strdup(((t_alloc*)src)->name);
        ft_sysint_alloc(ft_atoi((char*)(((t_alloc*)(src))->content)), old);
        ft_strdel(&old);
    }
}

void        ft_sysstr_convert(void)
{
    ft_alloc_cnvrt_add("str", "int", ft_sysstr_to_int);
}
