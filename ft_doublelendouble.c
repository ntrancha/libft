/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublelendouble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 20:05:27 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/27 20:05:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_doublelendouble(double n)
{
	size_t	size;
	size_t	size2;
	int		i;

	i = ft_dtoi(n);
	size2 = ft_nbrlen(i) + 1;
	size = ft_doublelen(n) - size2;
	if (size < 1)
		return (0);
	return (size);
}
