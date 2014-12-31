/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 21:54:50 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/26 21:54:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_putfloat(float n)
{
	char	*str;

	str = ft_ftoa(n);
	ft_putstr(str);
	ft_strdel(&str);
}
