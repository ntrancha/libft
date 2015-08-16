/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 20:24:49 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 22:54:45 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/libft.h"

t_fdos              *ft_getdir(char *path)
{
    t_fdos          *dir;
    struct dirent   *file;
    DIR             *rep;

    rep = ft_opendir(path);
    dir = ft_listcreate();
    if (rep == NULL || dir == NULL)
        return (NULL);
    while ((file = readdir(rep)))
        ft_listadd(dir, (void *)ft_fileinfo(file->d_name));
    ft_closedir(rep);
    return (dir);
}
