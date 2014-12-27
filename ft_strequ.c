/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:00:33 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/11 13:27:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 == s2)
		return (EXIT_SUCCES);
	if (!s1 || !s2 || !*s1 || !*s2)
		return (EXIT_NULL);
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (EXIT_NULL);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (EXIT_SUCCES);
	return (EXIT_NULL);
}
