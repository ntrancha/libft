/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdirtab_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 11:10:53 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/03 12:33:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/put.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

char        **ret_create(char ** files)
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

char        **ft_getdirtab_f(char *path, char *error, char type)
{
    char    **files;
    char    **ret;
    t_file  *file;
    int     index;
    int     count;

    if ((files = ft_getdirtab(path, error)) == NULL)
        return (NULL);
    ret = ret_create(files);
    index = -1;
    count = 0;
    while (files[++index])
    {
        if ((file = ft_fileinfo(files[index])) == NULL)
            return (NULL);
        if (ft_filetype(file) == type)
            ret[count++] = ft_strdup(files[index]);
        ft_strdel(&(file->name));
        ft_memdel((void**)(&(file)));
    }
    ft_tabstrdel(files);
    return (ret);
}
