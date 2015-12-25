/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:59:20 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/25 07:41:47 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/convert.h"
#include "../../includes/put.h"
#include "../../includes/bits.h"
#include "../../includes/strings.h"

void    ft_puthexa(t_octet *octet, char del)
{
    int index;

    index = 0;
    while (octet[index])
    {
        ft_putstr(ft_dectohex((int)octet[index++]));
        if (del != 0)
            ft_putchar(del);
    }
}
