/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcleanfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 15:30:15 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:50:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char		*ft_strcleanfront(char *str, char c)
{
	char	*tmp;
	int		index;

	index = 0;
	while (str[index] == c)
		index++;
	if (!(tmp = ft_strsub(str, index, ft_strlen(str) - index)))
		return (NULL);
	return (tmp);
}
