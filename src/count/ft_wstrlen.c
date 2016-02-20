/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:23:52 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 03:11:59 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_wstrlen(const char *str)
{
	size_t	count;
    int     h;
    int     hc;

	count = -1;
    h = 0;
    hc = 0;
	while (str[++count] != '\0')
        h = (!h && str[count] < 0) ? 1 : (str[count] < 0 && ++hc) ? 0 : 0;
	return (count - hc);
}
