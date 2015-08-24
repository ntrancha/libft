/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 22:43:45 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 23:02:42 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

void	ft_strtolower(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		str[index] = ft_tolower(str[index]);
		index++;
	}
}
