/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmore.c   									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 08:18:45 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:58:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char		*ft_strmore(char *str, size_t n)
{
	char	*ret;

	if (!str || ft_strlen(str) >= n)
		return (str);
	ret = ft_strnew(n);
	ret = ft_strcpy(ret, str);
	return (ret);
}
