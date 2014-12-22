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

#include <fcntl.h>
#include <unistd.h>
#include "includes/libft.h"

int             ft_readfile(int const fd, char **all)
{
    char        *tmp;
    int         ret;
	char		*line;

    ret = BUFF_SIZE;
    tmp = NULL;
	line = NULL;
	if (*all == NULL)
		*all = ft_strnew(0);
    while (ret)
    {
        ft_strdel(&line);
        line = ft_strnew(BUFF_SIZE + 2);
        if ((ret = read(fd, line, BUFF_SIZE)) == -1 || line == NULL)
            return (-1);
        tmp = ft_strnew(ft_strlen(*all) + BUFF_SIZE + 2);
        ft_strcpy(tmp, *all);
        ft_strdel(all);
        tmp = ft_strncat(tmp, line, ret);
        *all = ft_strnew(ft_strlen(tmp) + BUFF_SIZE + 2);
        ft_strcpy(*all, tmp);
        ft_strdel(&tmp);
    }
    ft_strdel(&line);
    return (0);
}
