/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileindos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 06:15:54 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/23 10:40:11 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/list.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

int         ft_fileindos(char *path, char *error, char *file)
{
    t_list  *list;
    t_node  *node;
    int     ret;

    if (path == NULL)
        return (-1);
    list = (t_list*)ft_getdir(path, error);
    if (list == NULL)
        return (-1);
    node = list->start;
    ret = 0;
    while (node && ret == 0)
    {
        if (ft_strcmp((char*)node->content, file) == 0)
            ret = 1;
        node = node->next;
    }
    ft_listdel(list, ft_memdel);
    return (ret);
}
