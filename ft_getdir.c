/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 20:24:49 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 20:34:10 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/libft.h"

t_list              *ft_getdir(t_list *list, char *path)
{
    t_list          *dir;
    struct dirent   *file;
    DIR             *rep;

    rep = ft_opendir(path);
    dir = ft_listcreate();
    if (rep == NULL || dir == NULL)
        return (NULL);
    ft_listadd(list, (void *)dir);
    while ((file = readdir(rep)))
        ft_listadd(dir, (void *)ft_fileinfo(file->d_name));
    ft_closedir(rep);
    return (list);
}
