/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cache_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 21:38:56 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/21 21:09:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/mem.h"

void        ft_cache_set(void *content)
{
    t_alloc *alloc;

    alloc = ft_alloc_get("TMP_PROG");
    if (alloc && alloc->content)
       ft_memdel((void**)&(alloc->content));
    alloc->content = content;
}
