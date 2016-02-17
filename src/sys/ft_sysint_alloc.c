/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysint_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 08:21:09 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/17 08:32:45 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/mem.h"

void        *ft_sysint_alloc(int num, char *id)
{
    int     *alloc;

    if (!(alloc = ft_memalloc(sizeof(int))))
        return (NULL);
    *alloc = num;
    return (ft_alloc_create(alloc, 1, id, "int"));
}
