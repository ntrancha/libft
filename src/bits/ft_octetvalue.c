/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octetvalue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 09:20:26 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 16:49:45 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bits.h"

static int  ft42_power(int nbr, int power)
{
    int     ret;

    ret = 1;
    if (power == 0)
		return (1);
	if (nbr == 0)
        return (0);
    if (power == 1)
        return (nbr);
    while (power-- > 0)
        ret *= nbr;
    return (ret);
}

int		    ft_octetvalue(t_octet octet)
{
	int	    ret;
	int	    index;
	int     decale;

	decale = 7;
	index = 8;
	ret = 0;
	while (--index > -1)
		ret += ft_octetgetbit(octet, index) * ft42_power(2, decale--);
	return (ret);
}
