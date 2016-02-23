/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:27:12 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/23 19:43:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

int         ft_vartype_func(char *str)
{
    if (ft_strcmp(str, "del") == 0)
        return (1);
    if (ft_strcmp(str, "put") == 0)
        return (2);
    if (ft_strcmp(str, "cpy") == 0 || ft_strcmp(str, "copy") == 0)
        return (3);
    if (ft_strcmp(str, "cmp") == 0 || ft_strcmp(str, "compare") == 0)
        return (4);
    if (ft_strcmp(str, "fus") == 0 || ft_strcmp(str, "fusion") == 0)
        return (5);
    if (ft_strcmp(str, "len") == 0)
        return (6);
    if (ft_strcmp(str, "count") == 0)
        return (7);
    return (0);
}
