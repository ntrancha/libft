/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysint_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 08:21:09 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/17 10:32:42 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/mem.h"

void        *ft_sysint_alloc(int num, char *id)
{
    int     *alloc;
    void    *ret;

    if (!(alloc = ft_memalloc(sizeof(int))))
        return (NULL);
    *alloc = num;
    ret =  ft_alloc_erase(alloc, sizeof(int), id, "int");
    if (ret)
        return (ret);
    ft_memdel((void**)&alloc);
    return (NULL);
}
