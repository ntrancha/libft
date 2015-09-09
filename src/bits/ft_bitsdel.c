/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:39:13 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/09 06:39:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"
#include "../../includes/bits.h"

t_bits		*ft_bitsdel(t_bits *memory)
{
	ft_memdel((void*)&(memory->memory));
	ft_memdel((void*)&memory);
	return (NULL);
}

