/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strralloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 14:47:49 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/25 14:47:49 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strralloc(char **str, int len)
{
	int		size;
	char	*ret;

	size = ft_strlen(*str);
	if (len <= size)
		return (NULL);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	if (!(ret = ft_strcpy(ret, *str)))
		return (NULL);
	ft_strdel(str);
	*str = ret;
	return (ret);
}
