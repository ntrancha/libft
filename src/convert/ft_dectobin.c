/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:58:19 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:00:04 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/math.h"
#include "../../includes/convert.h"

static int	findpower(int nbr)
{
	int		ret;

	ret = 0;
	while ((ft_power(2, ret) * 2) <= nbr)
        ret++;
	return (ret);
}

int			ft_dectobin(int dec)
{
	int		tmp;
	int 	res;
	int 	ret;

	tmp = findpower(dec);
	ret = dec;
	res = 0;
	if (dec < 0)
		return (ft_neg(ft_dectobin(ft_neg(dec))));
	while (tmp >= 0)
	{
		if (dec >= ft_power(2, tmp))
		{
			res += 1 * ft_power(10, tmp);
			ret = dec - ft_power(2, tmp);
		}
		dec = ret;
		tmp--;
	}
	if (ret == 1)
		res += 1;
	return (res);
}
