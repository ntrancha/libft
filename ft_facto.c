/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_facto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 22:56:30 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/27 22:56:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_facto(int nb)
{
	int		i;
	int		ret;

	i = 0;
	ret = nb;
	if (nb == 1 || nb == 0)
		return (EXIT_SUCCES);
	if (nb >= 13 || nb < 0)
		return (EXIT_FAIL);
	while (++i < nb)
		ret *= (nb - i);
	return (ret);
}
