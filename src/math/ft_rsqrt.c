/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 22:58:47 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 05:52:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		ft_rsqrt(float nb)
{
	float	result;
	float	i;

	if (nb == 0)
		return (0);
	i = 1;
	if (nb > 1)
	{
		while (nb - i * i > 0)
			i++;
		if (i * i - nb > nb - (i - 1) * (i - 1))
			result = i;
		else
			result = i - 1;
	}
	else
		result = 1;
	result = 0.5 * (result + nb / result);
	result = 0.5 * (result + nb / result);
	result = 0.5 * (result + nb / result);
	return (result);
}
