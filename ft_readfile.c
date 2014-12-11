/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 11:32:26 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/11 13:57:15 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <fcntl.h>

int			ft_readfile(int fd, char **str)
{
	int		ret;
	char	*line;
	char	*tmp;

	ret = 1;
	while (ret > 0)
	{
		ret = ft_gnl(fd, &line);
		if (ret != -1)
		{
			tmp = ft_strdup(*str);
			ft_strdel(str);
			*str = ft_strjoin(tmp, line);
			ft_strdel(&tmp);
		}
		if (ret == 1)
		{
			tmp = ft_strdup(*str);
			ft_strdel(str);
			*str = ft_strjoin(tmp, "\n");
			ft_strdel(&tmp);
		}
	}
	return (ret);
}
