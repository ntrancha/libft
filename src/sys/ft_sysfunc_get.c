/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysfunc_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:39:21 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 15:33:02 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_funcs     *ft_sysfunc_get(char *var_name)
{
    t_type  *type;
    t_alloc *alloc;

    if (!(alloc = ft_alloc_get(var_name)))
        return (NULL);
    if (!(type = ft_vartype_get(alloc->type)))
        return (NULL);
    return (type->func);
}
