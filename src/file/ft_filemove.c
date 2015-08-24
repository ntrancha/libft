/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filemove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 20:58:10 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/23 21:34:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"

int         ft_filemove(char *file_src, char *path_dst)
{
    if (ft_filecopy(file_src, path_dst) != 1)
        return (-1);
    if (ft_filedel(file_src) == -1)
        return (0);
    return (1);
}
