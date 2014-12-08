/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:28:47 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/19 13:03:29 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*result;

	index = 0;
	if (s && f)
	{
		result = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		if (!result)
			return (NULL);
		while (s[index] != '\0')
		{
			result[index] = f(index, s[index]);
			index++;
		}
		result[index] = '\0';
		return (result);
	}
	return (NULL);
}
