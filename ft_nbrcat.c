/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 15:56:32 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/25 15:56:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_nbrcat(int nbr, int nbr2)
{
	if (nbr2 < 0)
		nbr2 = ft_abs(nbr2);
	if (nbr < 0)
		return (ft_neg(ft_nbrcat(ft_abs(nbr), nbr2)));
	return ((nbr * ft_power(10, ft_nbrlen(nbr2))) + nbr2);
}
