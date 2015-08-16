/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deldir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 20:24:49 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 20:31:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/libft.h"

static void     tfile_del(t_file *file)
{
    if (file->name)
        ft_strdel(&(file->name));
    free(file);
}

static void     dir_del(t_list *list)
{
    t_node      *node;
    t_node      *tmp;

    if (list)
    {
        node = list->start;
        while (node)
        {
            tmp = node->next;
            tfile_del(node->content);
            ft_memdel((void**)&node);
            node = tmp;
        }
    }
    ft_memdel((void**)&list);
}

void            ft_deldir(t_list *list)
{
    t_node      *node;
    t_node      *tmp;

    if (list)
    {
        node = list->start;
        while (node)
        {
            tmp = node->next;
            dir_del(node->content);
            ft_memdel((void**)&node);
            node = tmp;
        }
    }
    ft_memdel((void**)&list);
}
