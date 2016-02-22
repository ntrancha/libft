/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrsort_void.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 21:21:33 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/22 21:22:04 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void     ft_tabstrsort_void(void *ptr)
{
    t_alloc     *alloc;
    char        **tab;

    alloc = (t_alloc*)ptr;
    if (alloc && alloc->type && ft_strcmp(alloc->type, "tabstr") == 0)
    {
        tab = (char**)alloc->content;
        ft_tabstrsort(&tab, 1);
    }
}
