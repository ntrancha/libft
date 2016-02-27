/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower_void.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:55:12 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/27 20:00:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"

void     ft_strtolower_void(void *ptr)
{
    t_alloc     *alloc;

    alloc = (t_alloc*)ptr;
    if (ft_strcmp(alloc->type, "str") == 0)
        ft_strtolower((char*)alloc->content);
}
