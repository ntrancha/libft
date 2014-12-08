/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:06:02 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/19 13:38:56 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int					ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2 && n)
		if (ft_strncmp(s1, s2, n) == 0)
			return (1);
	return (0);
}
