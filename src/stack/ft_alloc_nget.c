/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_nget.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:28:33 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 01:28:41 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void            *ft_alloc_nget(void *var)
{
    t_alloc     *alloc;

    alloc = ft_alloc_getvoid(var);
    if (alloc && alloc->content)
        return (alloc->content);
    return (NULL);
}
