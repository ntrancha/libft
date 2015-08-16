/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 00:13:28 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 22:58:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/libft.h"

static t_file       *fileinfo_get(t_node *node)
{
    return (node->content);
}

void            ft_dirdisplay(t_fdos *list)
{
    t_node      *node;
    t_file      *file;

    if (list)
    {
        node = list->start;
        while (node)
        {
            ft_putendl(fileinfo_get(node)->name);
            node = node->next;
        }
    }
}   

int             main(void)
{
    t_fdos       *list;

    list = ft_getdir(".");
    ft_dirdisplay(list);
    ft_dir_del(list);
}
