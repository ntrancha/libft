/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fround.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 10:46:10 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/27 10:46:10 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libft.h"

float		ft_fround(float n, int p)
{
	int		count1;
	int		count2;
	float	tmp1;
	float	tmp2;

	if (p == 0)
		return (ft_itof(ft_ftoi(n)));
	if (p >= (int)ft_floatlenfloat(n))
		return (n);
	tmp1 = n;
	tmp2 = n;
	count1 = 1;
	count2 = 1;
	while ((int)ft_floatlenfloat(tmp1) > p && count1++)
		tmp1 += 0.000001;
	while (ft_ftoi(ft_floatlenfloat(tmp2)) > p && count2++)
		tmp2 -= 0.000001;
	if (count1 < count2)
		return (tmp1);
	return (tmp2);
}
