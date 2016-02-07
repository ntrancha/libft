/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:41:00 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 00:42:21 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

void        *ft_vartype_delete(t_type *var)
{
    t_type  *next;

    if (var)
    {
        next = var->next;
        if (var->type)
            ft_strdel(&(var->type));
        ft_memdel((void**)&var);
        ft_vartype_delete(next);
    }
    return (NULL);
}
