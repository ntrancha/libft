/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:25:02 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/19 13:03:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*result;

	if (s && f)
	{
		index = 0;
		result = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		while (s[index] != '\0')
		{
			result[index] = f(s[index]);
			index++;
		}
		result[index] = '\0';
		return (result);
	}
	return (NULL);
}
