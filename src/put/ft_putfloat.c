/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 21:54:50 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:38:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/put.h"
#include "../../includes/convert.h"

void		ft_putfloat(float n)
{
	char	*str;

	str = ft_ftoa(n);
	ft_putstr(str);
	ft_strdel(&str);
}
