/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:59:10 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/11 13:08:59 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		count;
	int		count2;
	char	*str;

	if (!s1 || !s2)
		return ((char *)s1);
	str = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	count = 0;
	count2 = 0;
	while (s1[count] != '\0')
	{
		str[count2++] = s1[count++];
	}
	count = 0;
	while (s2[count] != '\0')
	{
		str[count2++] = s2[count++];
	}
	str[count2] = '\0';
	return (str);
}
