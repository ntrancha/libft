/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathexist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 05:30:28 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/05 06:23:00 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/count.h"
#include "../../includes/strings.h"

static char *recup_dos(char *path)
{
    char    *tmp;

    if (ft_strcmp(path, ".") == 0 || ft_strcmp(path, "..") == 0)
        return (NULL);
    if (path[ft_strlen(path) - 1] == '/')
    {
        tmp = ft_strsub(path, 0, ft_strlen(path) - 1);
        if (ft_cinstr(tmp, '/') < 1)
        {
            ft_strdel(&tmp);
            return (ft_strdup("."));
        }
        else
        {
            ft_strdel(&tmp);
            return (ft_dinpath(path));
        }
    }
    if (ft_cinstr(path, '/') < 1)
        return (ft_strdup("."));
    return (ft_dinpath(path));
}

static char *previous_path(char * path)
{
    char    *tmp;
    char    *ret;

    if (path[ft_strlen(path) - 1] == '/')
        tmp = ft_strsub(path, 0, ft_strlen(path) - 1);
    else
        tmp = ft_strdup(path);
    ret = ft_finpath(tmp);
    ft_strdel(&tmp);
    return (ret);
}

int         ft_pathexist(char *path)
{
    int     ret;
    int     count;
    char    *dos;
    char    *file;
    char    **files;

    ret = 0;
    count = -1;
    dos = recup_dos(path);
    if (!dos)
        return (1);
    file = previous_path(path);
    if (!file)
        file = ft_strsub(path, 0, ft_strlen(path) - 1);
    ft_putendl(dos);
    ft_putendl(file);
    files = ft_getdirtab(dos, NULL);
    if (files)
        while (files[++count] && ret == 0)
            if (ft_strcmp(files[count], file) == 0)
                ret = 1;
    ft_strdel(&dos);
    ft_strdel(&file);
    ft_tabstrdel(files);
    return (ret);
}

