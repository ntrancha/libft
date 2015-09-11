/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octet_ror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 09:15:18 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/11 18:27:44 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_octet     ft_octet_ror(t_octet a, int ror)
{
    int     tmp;

	tmp = ft_octetgetbit(a, 0);
	a = ft_octet_shr(a, 1);
	a = ft_octetsetbit(a, 7, tmp);
	if (ror == 1)
		return (a);
	return (ft_octet_ror(a, --ror));
}
