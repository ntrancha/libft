/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdirtab_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 11:10:53 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/03 13:34:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/put.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

static char **ret_create(char ** files)
{
    char    **ret;
    int     max;

    max = 0;
    while (files[max])
        max++;
    if ((ret = ft_memalloc(sizeof(char*) * (max + 1))) == NULL)
        return (NULL);
    return (ret);
}

static int  next(char *pfile, char **ret, int count, char type)
{
    t_file  *file;

    if ((file = ft_fileinfo(pfile)) == NULL)
        return (-1);
    if (ft_filetype(file) == type)
        ret[count++] = ft_strdup(pfile);
    ft_strdel(&(file->name));
    ft_memdel((void**)(&(file)));
    return (count);
}

char        **ft_getdirtab_f(char *path, char *error, char type)
{
    char    **files;
    char    *pfile;
    char    **ret;
    int     index;
    int     count;

    if ((files = ft_getdirtab(path, error)) == NULL)
        return (NULL);
    ret = ret_create(files);
    index = -1;
    count = 0;
    while (files[++index])
    {
        if (ft_strcmp(path, ".") == 0)
            pfile = ft_strdup(files[index]);
        else
            pfile = ft_strmjoin(path, "/", files[index]);
        if (ft_strcmp(files[index], ".") && ft_strcmp(files[index], ".."))
            if ((count = next(pfile, ret, count, type)) == -1)
                return (NULL);
        ft_strdel(&pfile);
    }
    ft_tabstrdel(files);
    return (ret);
}
