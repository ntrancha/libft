/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:47:17 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/16 11:47:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_bintodec(int bin)
{
	int		res;
	int		len;
	char	*str;
	int		size;

	if (bin < 0)
		return (ft_neg(ft_bintodec(ft_neg(bin))));
	str = ft_itoa(bin);
	len = ft_strlen(str);
	size = len - 1;
	res = 0;
	while (--len >= 0)
		if (str[len] - 48 == 1)
			res += ft_power(2, size - len);
	if (str[size] == '1')
		res++;
	ft_strdel(&str);
	return (res);
}
