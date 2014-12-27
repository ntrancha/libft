/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatlenfloat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:12:44 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/26 23:12:44 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t      ft_floatlenfloat(float n)
{
    size_t  size;
    int     p;
    int     index;

    if (n < 0)
        return (ft_floatlenfloat(n * -1));
    p = ft_ftoi(n);
    size = 0;
    index = 10;
    n = n - p;
    while (index < 100000 && n > 0)
    {
        p = (n * index) + 0.001;
        n = (((n * index) - p) / index);
        index *= 10;
        size++;
    }
    return (size);
}
