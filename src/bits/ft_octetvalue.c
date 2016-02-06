/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octetvalue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 09:20:26 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/06 11:10:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_octetvalue(t_octet octet)
{
	int	ret;
	int	index;
	int decale;

	decale = 7;
	index = 8;
	ret = 0;
	while (--index > -1)
		ret += ft_octetgetbit(octet, index) * ft_power(2, decale--);
	return (ret);
}
