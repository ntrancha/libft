/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfilelist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 10:37:43 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/31 10:37:43 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "includes/libft.h"

int				ft_readfilelist(int const fd, t_list *list)
{
	int         ret;
	char        *line;

	ret = BUFF_SIZE;
	line = NULL;
	if (!list)
		return (EXIT_FAIL);
	while (ret)
	{
		line = ft_strnew(BUFF_SIZE + 2);
		if ((ret = read(fd, line, BUFF_SIZE)) == -1 || line == NULL)
			return (EXIT_FAIL);
		line[ret] = '\0';
		while ((int)ft_strlen(line) != ret)
			line[ft_strlen(line)] = '\a';
		list = ft_listadd(list, line);
	}
	return (EXIT_NULL);
}
