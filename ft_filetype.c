/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 02:30:13 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/17 03:20:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "includes/libft.h"

char    ft_filetype(t_file *file)
{
    if (!file)
        return (0);
    if (S_ISBLK(file->mode) || file->mode == DT_BLK)
        return ('b');
    if (S_ISCHR(file->mode) || file->mode == DT_CHR)
        return ('c');
    if (S_ISDIR(file->mode) || file->mode == DT_DIR)
        return ('d');
    if (S_ISFIFO(file->mode) || file->mode == DT_FIFO)
        return ('f');
    if (S_ISLNK(file->mode) || file->mode == DT_LNK)
        return ('l');
    if (S_ISREG(file->mode) || file->mode == DT_REG)
        return ('r');
    if (S_ISSOCK(file->mode) || file->mode == DT_SOCK)
        return ('s');
    if (file->mode == DT_UNKNOWN)
        return ('u');
    return (0);
}
