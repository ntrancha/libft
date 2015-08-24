/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 21:17:47 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:39:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/put.h"
#include "../../includes/convert.h"

void		ft_putlong(long n)
{
	char	*str;

	str = ft_ltoa(n);
	ft_putstr(str);
	ft_strdel(&str);
}
