/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:13:59 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/28 05:23:01 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void    ft_putbits(t_bits *memory, char del)
{
    int index;

    index = 0;
    ft_putnbr_endl(memory->octet);
    while (index < (int)memory->octet)
    {
        ft_putoctet((t_octet)memory->memory[index++]);
        if (index < (int)memory->octet)
            ft_putchar(del);
    }
    index = 0;
    ft_putchar('\n');
    while (index < (int)memory->octet)
    {
        ft_putnbr(ft_bitsgetoctet(memory, index++));
        if (index < (int)memory->octet)
            ft_putchar(del);
    }
    ft_putchar('\n');
    if (memory->octet == 4)
    {
        ft_putnbr_endl((int)memory->memory[2]);
    }
}

