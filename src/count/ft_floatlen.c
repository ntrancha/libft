/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 22:50:27 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:08:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/count.h"
#include "../../includes/convert.h"

size_t		ft_floatlen(float n)
{
	size_t	size;
	char	*tmp;
	char	*tmp2;

	if (!(tmp = ft_ftoa(n)))
		return (0);
	tmp2 = ft_strcleanback(tmp, '0');
	size = ft_strlen(tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (size);
}
