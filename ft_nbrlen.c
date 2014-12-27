/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 07:24:50 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/08 07:24:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_nbrlen(int nbr)
{
    int		ret;

    ret = 0;
	if (nbr == 0)
		return (1);
    if (nbr < 0)
    {
        nbr *= -1;
        ret = 1;
    }
    while (nbr > 0)
    {
        nbr /= 10;
        ret++;
    }
    return (ret);
}
