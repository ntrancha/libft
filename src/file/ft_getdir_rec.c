/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdir_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 02:48:24 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/06 11:21:35 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "../../includes/file.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"
#include "../../includes/put.h"
#include "../../includes/list.h"

t_dos               *parcour(t_dos *dos, char *path, char *error);

void                recurs(char *path, char *file, t_dos *dos, char *error)
{
    char            *tmp;

    if (ft_strcmp(path, ".") == 0)
        tmp = ft_strdup(file);
    else
        tmp = ft_strmjoin(path, "/", file);
    if (ft_strcmp(file, ".") != 0 && ft_strcmp(file, "..") != 0)
        parcour(dos, tmp, error);
    ft_strdel(&tmp);
}

char                *fchemin(char *path, char *file)
{
    char            *chemin;

    if (ft_strcmp(path, ".") == 0)
        chemin = ft_strdup(file);
    else if (ft_strcmp(path, "/") == 0)
        chemin = ft_strjoin("/", file);
    else
        chemin = ft_strmjoin(path, "/", file);
    return (chemin);
}

void                add(char *path, t_dos *dos, char *file)
{
    if (ft_strcmp(path, ".") == 0)
        ft_listadd(dos, (void *)ft_strdup(file));
    else if (ft_strcmp(path, "/") == 0)
        ft_listadd(dos, (void *)ft_strjoin("/", file));
    else
        ft_listadd(dos, (void *)ft_strmjoin(path, "/", file));
}

t_dos               *parcour(t_dos *dos, char *path, char *error)
{
    struct dirent   *file;
    struct stat     stats;
    DIR             *rep;
    char            *chemin;

    rep = ft_opendir(path, error);
    if (rep == NULL)
        return (NULL);
    while ((file = readdir(rep)))
    {
        chemin = fchemin(path, file->d_name);
        if (lstat(chemin, &stats) == -1)
            stat(chemin, &stats);
        if (S_ISDIR(stats.st_mode))
            recurs(path, file->d_name, dos, error);
        else
            add(path, dos, file->d_name);
        ft_strdel(&chemin);
    }
    ft_closedir(rep);
    return (dos);
}

t_dos               *ft_getdir_rec(char *path, char *error)
{
    t_dos           *dos;
    char            *tmp;

    if (path == NULL)
        return (NULL);
    if (path[ft_strlen(path) - 1] == '/' && ft_strcmp(path, "/") != 0)
        tmp = ft_strsub(path, 0, ft_strlen(path) - 1);
    else
        tmp = ft_strdup(path);
    if (tmp == NULL)
        return (NULL);
    dos = ft_listcreate();
    dos = parcour(dos, tmp, error);
    ft_strdel(&tmp);
    return (dos);
}
