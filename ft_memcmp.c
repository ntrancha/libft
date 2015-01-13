/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:12:29 by ntrancha          #+#    #+#             */
/*   Updated: 2015/01/12 09:41:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/macros.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_tmp;
	const unsigned char	*s2_tmp;

	s1_tmp = (const unsigned char *)s1;
	s2_tmp = (const unsigned char *)s2;
	if (!s1 || !s2)
		return (EXIT_NULL);
	while (n--)
	{
		if (*s1_tmp != *s2_tmp)
			return ((unsigned char)*s1_tmp - (unsigned char)*s2_tmp);
		s1_tmp++;
		s2_tmp++;
	}
	return (EXIT_NULL);
}
