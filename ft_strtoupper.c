/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 22:41:05 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/27 22:41:05 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_strtoupper(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		str[index] = ft_toupper(str[index]);
		index++;
	}
}
