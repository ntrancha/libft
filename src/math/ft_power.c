/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:15:45 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 05:52:10 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_power(int nbr, int power)
{
    int ret;

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
