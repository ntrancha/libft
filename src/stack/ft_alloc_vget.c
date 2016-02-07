/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_vget.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:28:14 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 01:28:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void            *ft_alloc_vget(char *id)
{
    t_alloc     *alloc;

    alloc = ft_alloc_get(id);
    if (alloc && alloc->content)
        return (alloc->content);
    return (NULL);
}
