/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:27:47 by ntrancha          #+#    #+#             */
/*   Updated: 2015/01/13 10:09:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_atoi(const char *str)
{
	int		ret;
	int		signe;

	ret = 0;
	if (!str)
		return (ret);
	signe = 1;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
			|| *str == '\r' || *str == '\v' || *str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + (*str++ - '0');
	return (ret * signe);
}
