/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdos_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 20:24:49 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/17 03:53:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/libft.h"

static void     tfile_del(t_file *file)
{
    if (file != NULL)
    {
        if (file->name != NULL)
            ft_strdel(&(file->name));
        ft_memdel((void**)&file);
    }
}

void     ft_fdos_del(t_fdos *list)
{
    t_node      *node;
    t_node      *tmp;

    if (list)
    {
        node = list->start;
        while (node)
        {
            tmp = node->next;
            tfile_del((t_file *) node->content);
            ft_memdel((void**)&node);
            node = tmp;
        }
    }
    ft_memdel((void**)&list);
}
