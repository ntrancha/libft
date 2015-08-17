/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdir_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 02:48:24 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/17 04:16:57 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "includes/libft.h"

t_dos                *parcour(t_dos *dos, char *path, char *error);

void                recurs(t_file *file, t_dos *dos, char *error, char *path)
{
    char            *tmp;

    if (ft_strcmp(file->name, ".") != 0 && ft_strcmp(file->name, "..") != 0)
    {
        if (ft_strcmp(path, ".") == 0)  
            tmp = ft_strdup(file->name);
        else
            tmp = ft_strmjoin(path, "/", file->name);
        parcour(dos, tmp, error);
        ft_strdel(&tmp);
    }
    ft_strdel(&(file->name));
    ft_memdel((void**)&file);
}

t_dos                *parcour(t_dos *dos, char *path, char *error)
{
    t_fdos          *dir;
    struct dirent   *file;
    DIR             *rep;
    t_file          *fichier;

    rep = ft_opendir(path, error);
    if (rep == NULL)
        return (NULL);
    dir = ft_listcreate();
    if (dir == NULL)
        return (NULL);
    while ((file = readdir(rep)))
    {
        fichier = ft_fileinfo(file->d_name);
        if (ft_filetype(fichier) == 'd')
            recurs(fichier, dos, error, path);
        else if (ft_listadd(dir, (void *)fichier) == NULL)
            return (NULL);
    }
    ft_fdos_displaycol(dir, 0);
    ft_listadd(dos, (void *)dir);
    ft_closedir(rep);
    return (dos);
}


t_dos               *ft_getdir_rec(char *path, char *error)
{
    t_dos           *dos;

    dos = ft_listcreate();
    parcour(dos, path, error);
    return (dos);
}
