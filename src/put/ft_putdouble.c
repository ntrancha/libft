/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 20:30:38 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:37:29 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/convert.h"
#include "../../includes/put.h"

void		ft_putdouble(double n)
{
	char	*str;

	str = ft_dtoa(n);
	ft_putstr(str);
	ft_strdel(&str);
}
