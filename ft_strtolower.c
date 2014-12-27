/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 22:43:45 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/27 22:43:45 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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
