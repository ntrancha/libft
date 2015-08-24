/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:59:10 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/23 20:35:26 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char		*ft_strmjoin(char const *s1, char const *s2, char const *s3)
{
	char	*str;
	char	*ret;

	if (!s1 || !s2 || !s3)
		return (NULL);
	str = ft_strjoin(s1, s2);
	if (str == NULL)
		return (NULL);
	ret = ft_strjoin(str, s3);
	if (ret == NULL)
		return (NULL);
	ft_strdel(&str);
	return (ret);
}
