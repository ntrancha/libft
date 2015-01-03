/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catfile_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 22:49:14 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/31 22:49:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_catfile_list(const int fd)
{
	int		ret;
	char	*str;

	ret = 42;
	str = NULL;
	while ((ret = ft_gnl_list(fd, &str)) == 1)
	{
		ft_putendl(str);
		ft_strdel(&str);
	}
	if (ret != -1)
		ft_putstr(str);
	ft_strdel(&str);
	return (ret);
}
