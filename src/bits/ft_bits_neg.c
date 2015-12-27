/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_neg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 04:21:46 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/27 04:22:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_bits          *ft_bits_neg(t_bits *mem)
{
    if (mem->memory[0] == 0)
        mem->memory[0] = 255;
    else
        return (NULL);
    return (mem);
}
