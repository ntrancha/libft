/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdirdeep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:33:50 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/03 12:45:04 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/put.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

int         ft_getdirdeep(char *path, char *error)
{
    char    **files;
    char    *newfile;
    int     index;
    int     ret;
    int     tmp;

    ret = 1;
    files = ft_getdirtab_f(path, error, 'd');
    index = -1;
    while (files[++index])
    {
        newfile = ft_strmjoin(path, "/", files[index]);
        tmp = ft_getdirdeep(newfile, error);
        if (tmp > ret)
            ret = tmp;
        ft_strdel(&newfile);
    }
    return (ret);
}
