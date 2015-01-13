/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:08:43 by ntrancha          #+#    #+#             */
/*   Updated: 2015/01/12 10:12:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		main(void)
{
	char	**ret;

	ret = ft_strsplit(STR(*****coucou*les*enfants***), '*');
	ft_putendl(ret[0]);
	ft_putendl(ret[1]);
	ft_putendl(ret[2]);
	return (0);
}
