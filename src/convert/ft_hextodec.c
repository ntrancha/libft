/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 06:45:13 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/06 06:59:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		convert_hexa(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else
		return (c - 55);
}

int		ft_hextodec(char *hex)
{
	int	ret;
	int	size;
	int	power;

	ret = 0;
	power = 0;
	size = ft_strlen(hex);
	while (--size >= 0)
		if (hex[size] == '-')
			return (ret * -1);
		else
			ret += convert_hexa(hex[size]) * ft_power(16, power++);
	return (ret);
}
