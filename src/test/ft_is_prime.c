/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 15:05:11 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 05:46:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/math.h"

int				ft_is_prime(int nbr)
{
	int			index;

	if (nbr < 0)
		nbr = ft_abs(nbr);
	if (nbr < 2)
		return (0);
	index = nbr - 1;
	while (index > 1)
	{
		if (!(nbr % index))
			return (0);
		index--;
	}
	return (1);
}
