/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 00:09:28 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 00:13:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/count.h"
#include "../../includes/list.h"

static int      ft_tabstrlenvoid(void *a)
{
    return (ft_tabstrlen((char**)a));
}

static int      ft_liststrlenvoid(void *a)
{
    return (ft_liststrlen((t_list*)a));
}

void        ft_syslen(void)
{
    t_type  *type;

    type = ft_vartype_get("liststr");
    type->len = ft_liststrlenvoid;
    type = ft_vartype_get("tabstr");
    type->len = ft_tabstrlenvoid;
}
