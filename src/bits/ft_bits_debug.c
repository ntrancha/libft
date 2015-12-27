/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 04:04:43 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/27 04:07:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void   ft_bits_debug(t_bits *mem)
{
    int count;
    int vide;

    count = -1;
    vide = 1;
    if (mem->memory[0] == 255 && ++count == 0)
        ft_putchar('-');
    while (++count < (int)mem->octet)
    {
       if (vide && mem->memory[count] != 0)
           vide = 0;
       if (!vide)
            ft_putnbr((int)mem->memory[count]);
    }
    if (vide)
        ft_putchar('0');
    ft_putendl("");
}

