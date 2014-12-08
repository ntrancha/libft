/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:26:49 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/10 12:41:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int				i;
	int				j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] && (i + j) < (int)n)
		{
			j++;
			if (!s2[j])
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
