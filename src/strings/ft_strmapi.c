/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:28:47 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:58:16 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  
#include "../../includes/strings.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*result;

	index = 0;
	if (s && f)
	{
		result = ft_strnew(ft_strlen((char *)s) + 1);
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
