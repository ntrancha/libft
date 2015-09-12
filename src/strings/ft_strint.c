/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 11:30:21 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/12 11:35:09 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char        *ft_strint(int size)
{
    int     index;
    char    *ret;

    if (size <= 0)
        return (NULL);
    ret = ft_strnew(size + 1);
    index = 0;
    while (index < size)
        ret[index++] = '0';
    return (ret);
}
