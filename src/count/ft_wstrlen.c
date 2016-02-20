/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:23:52 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 13:11:41 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#define CHARG    str[count] > -1 *
#define CHARL    && str[count] < -1 *

size_t		ft_wstrlen(const char *str)
{
	size_t	count;
    int     spec;

	count = -1;
    spec = 0;
	while (str[++count] != '\0')
        spec += (CHARG 39 CHARL 25) ? 1 : (CHARG 69 CHARL 49) ? 2 : 0;
	return (count - spec - 1);
}
