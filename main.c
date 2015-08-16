/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 00:13:28 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 12:14:07 by ntrancha         ###   ########.fr       */
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
            ft_tfile_del(node->content);
            ft_memdel((void**)&node);
            node = tmp;
        }
    }
    ft_memdel((void**)&list);
}

t_list              *ft_getdir(char *path)
{
    t_list          *dir;
    struct dirent   *file;
    DIR             *rep;
    int             test;

    test = 1;
    rep = ft_opendir(path);
    dir = ft_listcreate();
    if (rep == NULL || dir == NULL)
        return (NULL);
    while (test)
    {
        file = readdir(rep);
        if (file)
        {
            ft_listadd(dir, (void *)ft_fileinfo(file->d_name));
        }
        else
            test = 0;
    }
    ft_closedir(rep);
    return (dir);
}

int     main(void)
{
    t_list          *dir;

    dir = ft_getdir(".");
    ft_list_del(dir);
}
