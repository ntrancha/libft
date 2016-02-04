/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathisfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 05:30:28 by ntrancha          #+#    #+#             */
/*   Updated: 2016/01/05 10:25:26 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/count.h"
#include "../../includes/strings.h"

static char *recup_dos(char *path)
{
    if (ft_strcmp(path, ".") == 0 || ft_strcmp(path, "..") == 0)
        return (NULL);
    if (path[ft_strlen(path) - 1] == '/')
        return (NULL);
    if (ft_cinstr(path, '/') < 1)
        return (ft_strdup("."));
    return (ft_dinpath(path));
}

int         ft_pathisfile(char *path)
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
        return (0);
    file = ft_finpath(path);
    files = ft_getdirtab(dos, NULL);
    if (files)
        while (files[++count] && ret == 0)
            if (ft_strcmp(files[count], file) == 0)
                ret = 1;
    ft_strdel(&dos);
    ft_strdel(&file);
    return (ret);
}

