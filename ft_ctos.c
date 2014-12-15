/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 17:34:54 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/15 17:34:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char		*ft_ctos(char c)
{
	char	*ret;

	ret = ft_strnew(1);
	if (ret != NULL)
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}
