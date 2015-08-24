/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 22:49:14 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:22:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/file.h"
#include "../../includes/macros.h"

int			ft_catfile(const int fd)
{
	int		ret;
	char	*line;
	char	*tmp;

	ret = BUFF_SIZE;
	line = NULL;
	while (ret)
	{
			line = ft_strnew(BUFF_SIZE + 2);
			if ( line == NULL || (ret = read(fd, line, BUFF_SIZE)) == -1 )
					return (-1);
			line[ret] = '\0';
			while ((int)ft_strlen(line) != ret)
					line[ft_strlen(line)] = '\a';
			tmp = ft_ctos('\a');
			ft_strnrpl(&line, tmp, "", -1);
			ft_strdel(&tmp);
			ft_putstr(line);
			ft_strdel(&line);
	}
	return (0);
}
