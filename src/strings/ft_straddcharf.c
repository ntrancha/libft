/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddcharf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 10:45:00 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/12 11:00:24 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void        ft_straddcharf(char **str, char c)
{
    char    *tmp;
    char    *tmp2;
    int     index;

    index = -1;
    if (*str)
        tmp = ft_strdup(*str);
    else
        tmp = ft_strdup("");
    ft_strdel(str);
    tmp2 = ft_memalloc(sizeof(char) * ft_strlen(tmp) + 2);
    tmp2[0] = c;
    while (tmp[++index])
        tmp2[index + 1] = tmp[index];
    tmp2[index + 1] = '\0';
    *str = ft_strdup(tmp2);
    ft_strdel(&tmp);
    ft_strdel(&tmp2);
}
