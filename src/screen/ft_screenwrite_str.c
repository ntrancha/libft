/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenwrite_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:50:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:16:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"

int             ft_screenwrite_str(char *str, char *spec)
{
    int         count;
    int         index;

    count = 0;
    index = 0;
    if (!str)
        return (count);
    while (str[index])
    {
        count += ft_screenwrite_char(str[index], spec);
        index++;
    }
    return (count);
}
