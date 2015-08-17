/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dos_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 20:24:49 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/17 04:09:10 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/libft.h"

void            ft_dos_del(t_dos *list)
{
    t_node      *node;
    t_node      *tmp;

    if (list)
    {
        node = list->start;
        while (node)
        {
            tmp = node->next;
            ft_fdos_del((t_fdos *) node->content);
            ft_memdel((void**)&node);
            node = tmp;
        }
    }
    ft_memdel((void**)&list);
}
