/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 23:02:51 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/27 23:02:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static float	ft_check_angle(float angle)
{
	while (angle > 360 || angle < -360)
	{
		if (angle > 360)
			angle -= 360;
		else
			angle += 360;
	}
	if (angle > 180)
		angle -= 360;
	else if (angle < -180)
		angle += 360;
	return (angle);
}

float			ft_cos(float angle)
{
	float		ret;
	int			n;
	float		angle2;

	angle = ft_check_angle(angle);
	angle2 = angle * 3.14 / 180;
	n = 1;
	ret = 1;
	while (n < 5)
	{
		ret += POWER(-1, n) * ((POWER(angle2, n + n) / FACTO(n + n)));
		n++;
	}
	if (ret > 1)
		return (EXIT_SUCCES);
	if (ret < -1)
		return (EXIT_FAIL);
	return (ret);
}
