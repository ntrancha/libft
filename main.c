/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 00:13:28 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 02:58:55 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/libft.h"

t_dir               *ft_newdir()
{
    t_dir           *dir;

    dir = ft_memalloc(sizeof(t_dir));
    if (dir == NULL)
        return (NULL);
    dir->path = NULL;
    dir->size = 0;
    dir->next = NULL;
    dir->prev = NULL;
    return (dir);
}

t_files             *ft_newfiles(void)
{
    t_files         *files;

    files = ft_memalloc(sizeof(t_files));
    if (files == NULL)
        return (NULL);
    files->file = NULL;
    files->next = NULL;
    files->prev = NULL;
}


t_dir               *ft_getdir(char *path)
{
    t_dir           *dir;
    struct dirent   *file;
    DIR             *rep;
    int             test;

    test = 1;
    rep = ft_opendir(path);
    dir = ft_newdir();
    if (rep == NULL || dir == NULL)
        return (NULL);
    while (test)
    {
        file = readdir(rep);
        if (file)
        {
        }
        else
            test = 0;
    }
    ft_closedir(rep);
}

int     main(void)
{
    ft_getdir(".");
}
