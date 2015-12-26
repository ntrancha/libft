/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitscopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 04:19:38 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/26 04:25:55 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_bits      *ft_bitscopy(t_bits *mem)
{
    t_bits  *new;

    if (!mem)
        return (NULL);
    new = ft_memalloc(sizeof(t_bits));
    if (!new)
        return (NULL);
    new->octet = mem->octet;
    new->memory = ft_memalloc(mem->octet + 1);
    ft_memcpy(new->memory, mem->memory, mem->octet);
	new->memory[mem->octet] = 0;
    return (new);
}
