/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:49:14 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:48:35 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char				*ft_strcat(char *s1, char const *s2)
{
	unsigned int	count;
	unsigned int	count2;

	count = ft_strlen(s1);
	count2 = 0;
	while (s2[count2] != '\0')
	{
		s1[count + count2] = s2[count2];
		count2++;
	}
	s1[count + count2] = '\0';
	return (s1);
}
