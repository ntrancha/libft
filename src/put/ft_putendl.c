/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:32:07 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:37:44 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/put.h"

void		ft_putendl(char const *s)
{
	char	*str;

	if (s)
	{
		str = (char *)s;
		ft_putstr(str);
		ft_putchar('\n');
	}
}
