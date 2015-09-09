/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitssetoctet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:40:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/09 06:41:38 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bits.h"

t_octet		ft_bitssetoctet(t_bits *memory, int n_octet, t_bin octet)
{
    t_bin   ret;

    if (!memory || !memory->memory || !memory->memory[n_octet])
        return (0);
    ret = memory->memory[n_octet];
    memory->memory[n_octet] = octet;
    return (ret);
}
