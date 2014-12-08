/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:32:01 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/21 09:25:21 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;

	if (!n)
		return (0);
	i = 0;
	while (s1 && s2 && i < n)
	{
		if (!(*s1 || *s2) || (*s1 != *s2))
			return ((int)(((unsigned char)*s1) - (unsigned char)*s2));
		s1++;
		s2++;
		i++;
	}
	return (0);
}
