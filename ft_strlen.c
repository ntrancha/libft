/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:23:52 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/10 12:43:42 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_strlen(char *str)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
