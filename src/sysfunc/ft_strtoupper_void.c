/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper_void.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:58:44 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/27 20:01:26 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"

void     ft_strtoupper_void(void *ptr)
{
    t_alloc     *alloc;

    alloc = (t_alloc*)ptr;
    if (ft_strcmp(alloc->type, "str") == 0)
        ft_strtoupper((char*)alloc->content);
}
