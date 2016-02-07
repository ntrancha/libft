/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 04:04:43 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 16:39:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/bits.h"

static void ft42_putchar(char c)
{
    write(1, &c, 1);
}

void        ft42_putnbr(int nb)
{
    if (nb < 0)
    {
        ft42_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
    {
        ft42_putnbr(nb / 10);
        ft42_putnbr(nb % 10);
    }
    else
        ft42_putchar(nb + '0');
}

void        ft_bits_debug(t_bits *mem)
{
    int     count;
    int     vide;

    count = -1;
    vide = 1;
    if (mem->memory[0] == 255 && ++count == 0)
        ft42_putchar('-');
    while (++count < (int)mem->octet)
    {
        if (vide && mem->memory[count] != 0)
            vide = 0;
        if (!vide)
            ft42_putnbr((int)mem->memory[count]);
    }
    if (vide)
        ft42_putchar('0');
    ft42_putchar('\n');
}
