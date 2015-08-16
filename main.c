/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 00:13:28 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 23:32:49 by ntrancha         ###   ########.fr       */
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
            if (strcmp(fileinfo_get(node)->name, "Makefile") == 0)
                ft_putendl(fileinfo_get(node)->name);
            node = node->next;
        }
    }
}   

int             main(void)
{
    t_fdos       *list;

    list = ft_getdir("toto", NULL);
    //ft_dirdisplay(list);
    ft_fdos_del(list);
}
