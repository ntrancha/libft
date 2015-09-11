/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_shr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 09:06:24 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/11 09:09:38 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_octet     ft_bits_shr(t_octet a, int shr)
{
    if (shr < 1 || shr > 7)
        return (0);
    return (a >> shr);
}
