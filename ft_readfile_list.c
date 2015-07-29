/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 02:31:03 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/29 02:55:33 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

int         ft_readfile_list(int const fd, t_list *list)
{
	int		ret;
	char	*line;
	char	*tmp;

	ret = BUFF_SIZE;
	line = NULL;
	if (!list)
		return (EXIT_FAIL);
	while (ret)
	{
		line = ft_strnew(BUFF_SIZE + 2);
		if ( line == NULL || (ret = read(fd, line, BUFF_SIZE)) == -1 )
			return (EXIT_FAIL);
		line[ret] = '\0';
		while ((int)ft_strlen(line) != ret)
			line[ft_strlen(line)] = '\a';
		tmp = ft_ctos('\a');
		ft_strnrpl(&line, tmp, "", -1);
		ft_strdel(&tmp);
		list = ft_listadd(list, line);
	}
	return (EXIT_NULL);
}

