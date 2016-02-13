/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_getsize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:33:37 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/13 15:36:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

size_t      ft_vartype_getsize(char *type)
{
    t_type  *var;

    if (!(var = ft_vartype_get(type)))
        return (0);
    return (var->n_octet);
}
