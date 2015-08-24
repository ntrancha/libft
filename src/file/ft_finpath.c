/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 10:12:02 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/23 10:32:42 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/put.h"
#include "../../includes/strings.h"

char        *ft_finpath(char *pathfile)
{
    char    *ret;
    int     size;

    ret = NULL;
    size = ft_strlen(pathfile) - 1;
    while (pathfile[size] && pathfile[size] != '/')
        size--;
    if (size == (int)ft_strlen(pathfile) - 1)
        return (NULL);
    ret = ft_strsub(pathfile, size + 1, ft_strlen(pathfile) - size + 1);
    return (ret);
}
