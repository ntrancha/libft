/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_memmove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:09:54 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/14 12:03:06 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void            *ft_stack_memmove(void *dst, void *src, size_t len)
{
    void        *ptr;

    ptr = ft_memmove(dst, src, len);
    return (ptr);
}
