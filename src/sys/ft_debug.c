/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:26:28 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/17 00:24:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void        ft_debug(const char *file, const char *func, int line)
{
    char    *str;

    if (file && func)
    {
        str = ft_strdup(file);
        if (!(DSTR(str, "__FILE__")))
            ft_strdel(&str);
        str = ft_strdup(func);
        if (!(DSTR(str, "__FUNC__")))
            ft_strdel(&str);
        str = ft_itoa(line);
        if (!(DSTR(str, "__LINE__")))
            ft_strdel(&str);
    }
}
