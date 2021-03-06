/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrvs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 14:26:04 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 23:01:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char		*ft_strrvs(char *str)
{
	int		index;
	int		count;
	char	*ret;

	index = 0;
	count = ft_strlen(str);
	ret = ft_strnew(count + 1);
	ret[count] = '\0';
	while (str[index])
	{
		ret[count - 1] = str[index];
		index++;
		count--;
	}
	return (ret);
}
