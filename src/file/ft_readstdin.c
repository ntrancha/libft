/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readstdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 02:55:42 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/15 23:57:02 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/file.h"
#include "../../includes/list.h"
#include "../../includes/macros.h"

int         ft_readstdin(char **str)
{
    int		ret;
	char	*line;
    t_list  *list;

	ret = BUFF_SIZE;
    list = ft_listcreate();
	if (!list)
		return (EXIT_FAIL);
    if (*str)
        ft_strdel(str);
	while (ret)
	{
		line = ft_strnew(BUFF_SIZE + 2);
		if ( line == NULL || (ret = read(0, line, 1)) == -1 )
			return (EXIT_FAIL);
		line[ret] = '\0';
		list = ft_listadd(list, line);
        if (*line == '\n')
        {
            *str = ft_listtostr(list);
            ft_listdel(&list, ft_memdel);
            return (1);
        }
	}
	return (EXIT_NULL);
}
