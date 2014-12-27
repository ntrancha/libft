/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 22:50:27 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/26 22:50:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_floatlen(float n)
{
	size_t	size;
	int		p;
	int		index;

	if (n < 0)
		return (ft_floatlen(n * -1) + 1);
	p = ft_ftoi(n);
	size = ft_nbrlen(p);
	index = 10;
	n = n - p;
	while (index < 100000 && n > 0)
	{
		p = (n * index) + 0.001;
		n = (((n * index) - p) / index);
		index *= 10;
		size++;
		if (n <= 0)
			size++;
	}
	return (size);
}
