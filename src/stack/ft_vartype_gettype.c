/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_gettype.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:58:17 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 00:58:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

char        *ft_vartype_gettype(char *type)
{
    t_type      *var;

    var = ft_vartype_get(type);
    return (var->type);
}
