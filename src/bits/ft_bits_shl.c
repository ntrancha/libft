/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_shl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 09:06:24 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/11 09:09:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_octet     ft_bits_shl(t_octet a, int shl)
{
    if (shl < 1 || shl > 7)
        return (0);
    return (a >> shl);
}