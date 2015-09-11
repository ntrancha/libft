/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octet_rol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 09:15:18 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/11 18:24:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_octet     ft_octet_rol(t_octet a, int rol)
{
    int     tmp;

	tmp = ft_octetgetbit(a, 7);
	a = ft_octet_shl(a, 1);
	a = ft_octetsetbit(a, 0, tmp);
	if (rol == 1)
		return (a);
	return (ft_octet_rol(a, --rol));
}
