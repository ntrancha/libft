/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmmjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:59:10 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/23 20:38:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char		*ft_strmmjoin(t_cchar *s1, t_cchar *s2, t_cchar *s3, t_cchar *s4)
{
	char	*str;
	char	*ret;

	if (!s1 || !s2 || !s3 || !s4)
		return (NULL);
	str = ft_strmjoin(s1, s2, s3);
	if (str == NULL)
		return (NULL);
	ret = ft_strjoin(str, s4);
	if (ret == NULL)
		return (NULL);
	ft_strdel(&str);
	return (ret);
}
