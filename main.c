/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 00:13:28 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 12:36:29 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/libft.h"

void                ft_tfile_del(t_file *file)
{
    if (file->name)
        ft_strdel(&(file->name));
    free(file);
}

void                ft_dir_del(t_list *list)
{
    t_node          *node;
    t_node          *tmp;

    if (list)
    {
        node = list->start;
        while (node)
        {
            tmp = node->next;
            ft_tfile_del(node->content);
            ft_memdel((void**)&node);
            node = tmp;
        }
    }
    ft_memdel((void**)&list);
}

void                ft_list_del(t_list *list)
{
    t_node          *node;
    t_node          *tmp;

    if (list)
    {
        node = list->start;
        while (node)
        {
            tmp = node->next;
            ft_dir_del(node->content);
            ft_memdel((void**)&node);
            node = tmp;
        }
    }
    ft_memdel((void**)&list);
}

t_list              *ft_getdir(char *path)
{
    t_list          *dir;
    t_list          *list;
    struct dirent   *file;
    DIR             *rep;

    rep = ft_opendir(path);
    dir = ft_listcreate();
    list = ft_listcreate();
    ft_listadd(list, (void *)dir);
    if (rep == NULL || dir == NULL)
        return (NULL);
    while (file = readdir(rep))
        ft_listadd(dir, (void *)ft_fileinfo(file->d_name));
    ft_closedir(rep);
    return (list);
}

int     main(void)
{
    t_list          *dir;

    dir = ft_getdir(".");
    ft_list_del(dir);
}
