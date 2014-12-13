/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:06:02 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/11 14:10:34 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int					ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int				count;

	count = (int)n + 1;
	if (s1 == s2)
		return (1);
	if (!s1 || !s2 || !*s1 || !*s2)
		return (0);
	while (*s1 && *s2 && count--)
	{
		if (*s1 != *s2 && count > 0)
			return (0);
		s1++;
		s2++;
	}
	if (count > -1 && *s1 == *s2)
		return (1);
	return (0);
}
