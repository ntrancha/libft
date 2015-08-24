/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgetline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 17:26:48 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:53:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char    *ft_strgetline(const char *str, int line)
{
    int index;
    int start;

    index = 0;
    start = 0;
    if (!str || line < 0)
        return (NULL);
    while (str[index])
        if (str[index++] == '\n')
        {
            if (--line == 0 && start == 0)
                start = index;
            else if (line == -1 || !str[index])
                return (ft_strsub(str, start, (index - start - 1)));
        }
    if (start != 0)
        return (ft_strsub(str, start, (index - start)));
    return (NULL);
}
