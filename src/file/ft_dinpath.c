/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 10:12:02 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/23 10:27:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/put.h"
#include "../../includes/strings.h"

char        *ft_dinpath(char *pathfile)
{
    char    *ret;
    int     size;

    ret = NULL;
    size = ft_strlen(pathfile) - 1;
    while (pathfile[size] && pathfile[size] != '/')
        size--;
    if (size == (int)ft_strlen(pathfile))
            return (NULL);
    if (size <= 0 && pathfile[0] == '/')
        return (ft_strdup("/"));
    else if (size <= 0)
        return (NULL);
    ret = ft_strsub(pathfile, 0, size);
    return (ret);
}
