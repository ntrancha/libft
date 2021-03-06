/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 15:05:11 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 16:52:59 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft42_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int				ft_is_prime(int nbr)
{
	int			index;

	if (nbr < 0)
		nbr = ft42_abs(nbr);
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
