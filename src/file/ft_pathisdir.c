/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathisdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 08:45:07 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/05 05:42:31 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/count.h"
#include "../../includes/strings.h"

static int  pathisdir_next(char **files, char *dos, char *tmp, char *path)
{
	int		count;
	int		ret;

    count = -1;
	ret = 0;
	while (files[++count])
		if (ft_strcmp(dos, files[count]) == 0)
			ret = 1;
	ft_tabstrdel(files);
	ft_strdel(&dos);
	ft_strdel(&tmp);
    if (ret == 1)
    {
        files = ft_getdirtab(path, NULL);
        if (!files)
            ret = 0;
        else
	        ft_tabstrdel(files);
    }
    return (ret);
}

static char *end_less(char *path)
{
	if (path[ft_strlen(path) - 1] == '/')
		return (ft_strsub(path, 0, ft_strlen(path) - 1));
	return (ft_strdup(path));
}

int			ft_pathisdir(char *path)
{
	char	*dos;
	char	*tmp;
	char	**files;

	if (ft_strcmp(path, ".") == 0 || ft_strcmp(path, "..") == 0)
		return (1);
    tmp = end_less(path);
    if (ft_cinstr(tmp, '/') < 1)
    	files = ft_getdirtab(".", NULL);
    else
    {
    	dos = ft_dinpath(tmp);
    	files = ft_getdirtab(dos, NULL);
	    ft_strdel(&dos);
    }
    if (!files)
        return (-1);
    if (ft_cinstr(tmp, '/') < 1)
        dos = ft_strdup(tmp);
    else
    	dos = ft_finpath(tmp);
	return (pathisdir_next(files,dos, tmp, path));
}
