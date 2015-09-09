/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbintocdec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 04:57:32 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/09 05:02:59 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int     ft_sbintocdec(char *str)
{
    int index;
    int test;

    index = -1;
    test = 1;
    while (str[++index])
        if (str[index] != '1' && str[index] != '0')
            test = 0;
    if (test == 0 || index > 8)
        return (-1);
    return (ft_bintodec(ft_atoi(str)));
}
