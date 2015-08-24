/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 17:34:54 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:00:24 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char		*ft_ctos(char c)
{
	char	*ret;

	ret = ft_strnew(1);
	if (ret == NULL)
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}
