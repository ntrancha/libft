/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sinttooct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 13:35:27 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/25 14:03:44 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_bits      *ft_sinttooct(char *str)
{
    int     count;
    int     test;
    char    *tmp;
    t_bits  *ret;

    count = -1;
    test = 0;
    tmp = ft_strdup(str);
    while (tmp[++count] && !test)
        if (tmp[count] >= '0' && tmp[count] <= '9')
            tmp[count] -= 48;
        else
            if (tmp[count] == '-' && !count)
                tmp[count] = 255;
            else
                test = 1;
    if (test)
    {
        ft_strdel(&tmp);
        return (NULL);
    }
    ret = ft_bitscreate((void*)tmp, ft_strlen(str));
    ft_strdel(&tmp);
    return (ret);
}
