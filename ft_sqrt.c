/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 14:57:28 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/25 14:57:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_sqrt(int nbr)
{
	int		index;

	if (nbr <= 1)
		RETURN_NULL;
	index = nbr;
	while (index > 1)
	{
		if ((index * index) == nbr)
			return (index);
		index--;
	}
	RETURN_NULL;
}
