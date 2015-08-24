/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 21:11:45 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:41:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/count.h"

size_t      ft_longlen(long nbr)
{
    long    ret;

    ret = 0;
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
