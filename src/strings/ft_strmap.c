/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:25:02 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:57:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*result;

	if (s && f)
	{
		index = 0;
		result = ft_strnew(ft_strlen((char *)s) + 1);
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
