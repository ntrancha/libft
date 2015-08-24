/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 20:39:38 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/23 21:48:53 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/strings.h"

int         ft_filecopy(char *file_src, char *path_dst)
{
    char    *content;
    char    *file;
    char    *file_s;
    char    *tmp;

    if (file_src == NULL || path_dst == NULL)
        return (-1);
    content = ft_get_file(file_src);
    if (content == NULL)
        return (-1);
    tmp = NULL;
    file = ft_finpath(path_dst);
    file_s = ft_finpath(file_src);
    if (file == NULL)
        tmp = ft_strjoin(path_dst, file_s);
    else
        tmp = ft_strdup(path_dst);
    ft_filedel(tmp);
    if (ft_write_file(tmp, content) == -1)
        return (-1);
    ft_strdel(&content);
    ft_strdel(&file);
    ft_strdel(&file_s);
    ft_strdel(&tmp);
    return (1);
}
