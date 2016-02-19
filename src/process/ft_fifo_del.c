/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fifo_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 09:45:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 09:54:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/mem.h"

int         ft_fifo_del(char *pathname)
{
    t_file  *file;    

    file = ft_fileinfo(pathname);
    if (!file)
        return (-1);
    if (ft_filetype(file) == 'f')
    {
        ft_memdel((void**)&file);
        unlink(pathname);
        return (1);
    }
    ft_memdel((void**)&file);
    return (0);
}
