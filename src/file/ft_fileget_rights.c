/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileget_rights.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 23:37:50 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:25:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "../../includes/file.h"

int         ft_fileget_rights(t_file *file)
{
    int     ret;

    ret = 0;
    if (S_ISDIR(file->mode))
        return (-1);
    if ((file->mode & S_IRUSR) != 0)
        ret += 400;
    if ((file->mode & S_IWUSR) != 0)
        ret += 200;
    if ((file->mode & S_IXUSR) != 0)
        ret += 100;
    if ((file->mode & S_IRGRP) != 0)
        ret += 40;
    if ((file->mode & S_IWGRP) != 0)
        ret += 20;
    if ((file->mode & S_IXGRP) != 0)
        ret += 10;
    if ((file->mode & S_IROTH) != 0)
        ret += 4;
    if ((file->mode & S_IWOTH) != 0)
        ret += 2;
    if ((file->mode & S_IXOTH) != 0)
        ret += 1;
    return (ret);
}
