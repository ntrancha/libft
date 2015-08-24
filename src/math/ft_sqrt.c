/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 14:57:28 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 05:53:16 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_sqrt(int nbr)
{
	int		index;

	if (nbr <= 1)
		return (0);
	index = nbr;
	while (index > 1)
	{
		if ((index * index) == nbr)
			return (index);
		index--;
	}
    return (0);
}
