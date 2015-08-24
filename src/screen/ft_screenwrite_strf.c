/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenwrite_strf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:50:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:17:04 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"

int             ft_screenwrite_strf(char *str, char *spec)
{
    int         count;
    int         index;

    count = 0;
    index = 0;
    if (!str)
        return (count);
    while (str[index])
    {
        count += ft_screenwrite_charf(str[index], spec);
        index++;
    }
    return (count);
}
