/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 16:21:51 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:40:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

int			ft_match(char const *str, char const *match)
{
	char	*tmp;

	while (*str && *match)
	{
		if (*match == '*')
		{
			match++;
			if (*match)
				return (1);
			tmp = ft_strchr(str, *match);
			if (!tmp)
				return (0);
			else
				str = tmp;
		}
		else if (*str == *match)
		{
			str++;
			match++;
		}
		else
			return (0);
	}
	return (*str && *match);
}
