/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdirdeep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:33:50 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/03 14:17:02 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

int         ft_getdirdeep(char *path, char *error)
{
    char    **files;
    int     index;
    int     ret;
    int     tmp;

    ret = 0;
    if ((files = ft_getdirtab_f(path, error, 'd')) == NULL)
        return (0);
    index = -1;
    while (files[++index])
        if (ft_strcmp(files[index], ".") && ft_strcmp(files[index], ".."))
            if ((tmp = ft_getdirdeep(files[index], error) + 1) > ret)
                ret = tmp;
    ft_tabstrdel(files);
    return (ret);
}
