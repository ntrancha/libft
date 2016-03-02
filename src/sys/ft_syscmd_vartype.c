/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_vartype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 21:57:47 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/02 21:58:52 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/stack.h"

int         ft_syscmd_vartype(char *var)
{
    t_alloc *alloc;

    if (ft_strisnum(var))
        return (1);
    if (var[0] == '"' && var[ft_strlen(var) - 1] == '"')
        return (2);
    alloc = ft_alloc_get(var);
    if (!alloc)
        return (0);
    if (ft_strcmp(alloc->type, "str") == 0)
        return (22);
    if (ft_strcmp(alloc->type, "int") == 0)
        return (11);
    return (0);
}
