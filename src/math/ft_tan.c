/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 23:11:27 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 05:53:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/math.h"
#include "../../includes/macros.h"

float	ft_tan(float angle)
{
	return (SIN(angle) / COS(angle));
}
