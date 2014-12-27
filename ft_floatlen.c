/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 22:50:27 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/26 22:50:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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
