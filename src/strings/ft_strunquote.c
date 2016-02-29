/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 20:47:25 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/28 21:00:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/put.h"

void        ft_strunquote(char **str, int c)
{
    int     start;
    char    *new;

    start = (str && *str && *str[0] == c) ? 1 : 0;
    new = ft_strsub(*str, start, ft_strlen(*str) - (start * 2)); 
    ft_strdel(str);
    *str = new;
}
