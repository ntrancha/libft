/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 23:49:43 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/27 23:54:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

void        ft_strreplace(char **str, char *old, char *new, int count)
{
    char    *ret;

    if (str && *str && old && new && count != 0)
        if (ft_strcchr(*str, old) != 0)
            if ((ret = ft_strremplace(*str, old, new)))
            {
                ft_strdel(str);
                *str = ret;
                ft_strreplace(str, old, new, count - 1);
            }
}
