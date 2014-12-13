/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:14:08 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/11 13:03:03 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	count;
	unsigned int	count2;
	int				taille;
	char			*result;

	taille = 0;
	if (!s || !*s)
		return (NULL);
	while (s[taille] != '\0')
		taille++;
	result = ft_strnew(taille);
	count = 0;
	count2 = 0;
	while (s[count] != '\0')
	{
		if (count >= start && count2 < len)
		{
			result[count2] = s[count];
			count2++;
		}
		count++;
	}
	result[count2] = '\0';
	return (result);
}
