/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcenter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 19:25:06 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/08 19:27:33 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void        ft_putcenter(char *str, int col)
{
    int     len;

    if (str)
    {
        len = ft_strlen(str) / 2;
        len = (col / 2) - len;
        ft_putspace(len);
        ft_putstr(str);
        ft_putspace(len);
    }
    else
        ft_putspace(col);
}
