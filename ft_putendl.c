/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:32:07 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/08 16:54:45 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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
