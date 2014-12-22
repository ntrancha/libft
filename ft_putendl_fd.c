/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:40:13 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/09 13:14:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

void		ft_putendl_fd(char const *s, int fd)
{
	char	endline;

	if (s && fd)
	{
		endline = '\n';
		ft_putstr_fd(s, fd);
		write(fd, &endline, 1);
	}
}
