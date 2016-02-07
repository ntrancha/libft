/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 04:20:34 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 16:32:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bits.h"

t_bits          *ft_bits_abs(t_bits *mem)
{
    if (mem->memory[0] == 255)
        mem->memory[0] = 0;
    else
        return (NULL);
    return (mem);
}
