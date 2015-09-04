/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathisdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 08:45:07 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/04 09:20:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/strings.h"

int			ft_pathisdir(char *path)
{
	char	*dos;
	char	*tmp;
	char	**files;
	int		count;
	int		ret;

	if (ft_strcmp(path, ".") == 0 || ft_strcmp(path, "..") == 0)
		return (1);
	if (path[ft_strlen(path) - 1] == '/')
		tmp = ft_strsub(path, 0, ft_strlen(path) - 1);
	else
		tmp = ft_strdup(path);
	dos = ft_dinpath(tmp);
	files = ft_getdirtab(dos, NULL);
	ft_strdel(&dos);
	dos = ft_finpath(tmp);
	count = -1;
	ret = 0;
	while (files[++count])
		if (ft_strcmp(dos, files[count]) == 0)
			ret = 1;
	ft_tabstrdel(files);
	ft_strdel(&dos);
	ft_strdel(&tmp);
	return (ret);
}
