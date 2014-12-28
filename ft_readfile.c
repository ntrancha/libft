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
    int         ret;
	char		*line;

    ret = BUFF_SIZE;
	line = NULL;
	if (*all == NULL)
		*all = ft_strnew(0);
    while (ret)
    {
        line = ft_strnew(BUFF_SIZE + 2);
        if ((ret = read(fd, line, BUFF_SIZE)) == -1 || line == NULL)
            return (EXIT_FAIL);
		while ((int)ft_strlen(line) != ret)
			line[ft_strlen(line)] = '\a';
		ft_strfusion(all, &line);
    }
    return (EXIT_NULL);
}
