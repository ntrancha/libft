/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:40:13 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:42:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/put.h"

void		ft_putendl_fd(char const *s, int fd)
{
	if (s && fd)
	{
		ft_putstr_fd(s, fd);
		ft_putstr_fd("\n", fd);
	}
}
