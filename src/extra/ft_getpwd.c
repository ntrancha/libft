/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:04:47 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/11 13:06:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/mem.h"

char        *ft_getpwd(void)
{
    char    *str;
    int     size;

    size = 1;
    str = ft_strnew(size + 1);
    while (!getcwd(str, size))
    {
        ft_strdel(&str);
        size += 10;
        str = ft_strnew(size + 1);
    }
    return (str);
}
