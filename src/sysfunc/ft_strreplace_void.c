/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace_void.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 20:12:20 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/27 23:57:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/put.h"
#define CNT     (char**)&alloc->content
#define CNT_S   (char*)alloc_s->content
#define CNT_R   (char*)alloc_r->content

void     ft_strreplace_void(void *ptr, void *search, void *replace)
{
    t_alloc     *alloc;

    alloc = (t_alloc*)ptr;
    if (alloc && alloc->type && ft_strcmp(alloc->type, "str") == 0)
        ft_strreplace(CNT, (char*)search, (char*)replace, -1);
}
