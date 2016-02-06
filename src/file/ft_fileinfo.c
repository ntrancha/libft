/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 00:46:20 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/06 11:18:07 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "../../includes/file.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

t_file      *ft_fileinfo(char *file)
{
    t_file          *struc;
    struct  stat    s;

    struc = ft_memalloc(sizeof(t_file));
    if (struc == NULL)
        return (NULL);
    if (lstat(file, &s) == -1)
        return (NULL);
    struc->name = ft_strdup(file);
    struc->mode = s.st_mode;
    struc->uid = s.st_uid;
    struc->gid = s.st_gid;
    struc->size = s.st_size;
    return (struc);
}
