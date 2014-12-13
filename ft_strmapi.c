/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:28:47 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/11 13:54:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*result;

	index = 0;
	if (*f && f)
		if (*s && s)
		{
			result = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
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
