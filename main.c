/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 00:13:28 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/17 04:10:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/libft.h"
#define NAME    fileinfo_get(node)->name
#define NAMEN   fileinfo_get(node->next)->name


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
            if (ft_filetype(node->content) == 'd') 
                ft_putendl(fileinfo_get(node)->name);
            node = node->next;
        }
    }
}   

void            ft_fdossort_name(t_list *list)
{
    t_node      *node;
    t_file      *file;

    if (list)
    {
        node = list->start;
        while (node && node->next)
        {
            if (ft_strcmp(NAME, NAMEN) > 1) 
            {
                ft_listswap(list, node, node->next);
                if (node->previous)
                    if (node->previous->previous)
                        node = node->previous->previous;
                    else
                        node = node->previous;
            }
            else
                node = node->next;
        }
    }

}

int             main(void)
{
    t_fdos       *list;
    t_dos        *rec;

    //list = ft_getdir(".", NULL);
    rec = ft_getdir_rec("includes", NULL);
    //ft_fdossort_name(list);
    //ft_fdos_displaycol(list, 0);
    ft_dirdisplay(rec->start->content);
    //ft_fdos_del(list);
    ft_dos_del(rec);
}
