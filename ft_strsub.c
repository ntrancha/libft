/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:14:08 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/19 14:52:04 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	count;
	char			*result;

	if (!s)
		return (NULL);
	result = ft_strnew(len + 1);
	if (!result)
		return (NULL);
	count = 0;
	while (count < len)
	{
		result[count] = s[start];
		count++;
		start++;
	}
	result[count] = '\0';
	return (result);
}
