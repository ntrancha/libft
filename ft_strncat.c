/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:44:18 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/08 15:44:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strncat(char *s1, char *s2, size_t n)
{
	int				count;
	unsigned int	count2;

	count = ft_strlen(s1);
	count2 = 0;
	while (s2[count2] != '\0' && n > count2)
	{
		s1[count + count2] = s2[count2];
		count2++;
	}
	s1[count + count2] = '\0';
	return (s1);
}
