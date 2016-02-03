/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdirdeep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:33:50 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/03 13:40:49 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/put.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

int         ft_getdirdeep(char *path, char *error)
{
    char    **files;
    //char    *newfile;
    int     index;
    int     ret;
    int     tmp;

    ret = 0;
    if ((files = ft_getdirtab_f(path, error, 'd')) == NULL)
        return (1);
    index = -1;
    while (files[++index])
        if (ft_strcmp(files[index], ".") && ft_strcmp(files[index], ".."))
            if ((tmp = ft_getdirdeep(files[index], error) + 1) > ret)
                ret = tmp;
    ft_tabstrdel(files);
    return (ret);
}
