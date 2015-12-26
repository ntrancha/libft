/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 23:48:51 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/26 01:02:33 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		bits_add_rpl(char*str, int size)
{
	int 	count;

	count = -1;
	while (++count < size)
	{
		
	}
}

t_bits      *ft_bits_add(t_bits *a, t_bits *b, int base)
{
	int		size_a;
	int		size_b;
	char	*tmp_a;
	char	*tmp_b;

	size_a = a->octet;	
	size_b = b->octet;
	tmp_a = ft_strdup(a->memory);
	tmp_b = ft_strdup(b->memory);
	while (a->octet > b->octet)
	{
		ft_straddcharf(&tmp_b, 254);
		size_b++;
	}
	while (a->octet < b->octet)
	{
		ft_straddcharf(&tmp_a, 254);
		size_a++;
	}
	bits_add_rpl(tmp_a, size_a);	
	bits_add_rpl(tmp_b, size_b);	
}
