/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 07:46:17 by ntrancha          #+#    #+#             */
/*   Updated: 2015/02/17 07:46:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strisnum(const char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str++) == 0)
			return (0);
	}
	return (1);
}
