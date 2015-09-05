/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathisfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 05:30:28 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/05 05:38:37 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/count.h"
#include "../../includes/strings.h"

int         ft_pathisfile(char *path)
{
    int     ret;
    char    *dos;
    char    *file;

    ret = 0;
    if (!ft_strcmp(path, ".") == 0 || ft_strcmp(path, "..") == 0)
        return (ret);
    if (path[ft_strlen(path) - 1] == '/')
        return (ret);
    if (ft_cinstr(tmp, '/') < 1)
        dos = ft_strdup(".");
    else
    {

    }
    return (ret);
}

