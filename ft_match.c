/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 16:21:51 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/29 16:21:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_match(char const *str, char const *match)
{
	char	*tmp;

	while (*str && *match)
	{
		if (*match == '*')
		{
			match++;
			if (*match)
				return (EXIT_SUCCES);
			tmp = ft_strchr(str, *match);
			if (tmp == NULL)
				return (EXIT_NULL);
			else
				str = tmp;
		}
		else if (*str == *match)
		{
			str++;
			match++;
		}
		else
			return (EXIT_NULL);
	}
	return (*str && *match);
}
