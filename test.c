/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 10:00:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/08 07:17:26 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

typedef unsigned char	t_octet;
typedef _Bool			t_bit;

typedef struct			s_mem
{
	t_octet				*memory;
	size_t				octet;
}						t_mem;

t_mem					*ft_bitscreate(void *memory, size_t octet);
t_mem					*ft_bitsdel(t_mem *memory);
t_octet					ft_bitsgetoctet(t_mem *memory, int octet);
t_octet					*ft_bitsgetaddr(t_mem *memory, int octet);



int			ft_bitsmodifbit(t_mem *memory, int octet, int bit, int value)
{
	if (ft_bitsgetoctet(memory, octet) == 0 || bit > 7)
		return (-1);
	if (value == 0)
		memory->memory[octet] &= ~(1 << bit);
	else
		memory->memory[octet] |= (1 << bit);
	return (value);
}

t_octet		*ft_bitsgetaddr(t_mem *memory, int octet)
{
	if (octet < ft_strlen(memory->memory))
		return (&memory->memory[octet]);
	return (0);
}

t_octet		ft_bitsgetoctet(t_mem *memory, int octet)
{
	if (octet < ft_strlen(memory->memory))
		return (memory->memory[octet]);
	return (0);
}

t_mem		*ft_bitscreate(void *memory, size_t octet)
{
	t_mem	*mem;

	mem = ft_memalloc(sizeof(t_mem));
	if (!mem)
		return (NULL);
	if (!memory)
	{
		mem->memory = NULL;
		mem->octet = 0;
	}
	else
	{
		mem->memory = ft_memalloc(octet + 1);
	   	ft_memcpy(mem->memory, memory, octet);
		mem->memory[octet] = 0;
		mem->octet = octet;
	}
	return (mem);
}

t_mem		*ft_bitsdel(t_mem *memory)
{
	ft_memdel((void*)&(memory->memory));
	ft_memdel((void*)&memory);
	return (NULL);
}

int		main(void)
{
	t_mem	*mem;
	char	*str;
	size_t	size;

	str = ft_strdup("Nk42");
	size = sizeof(str);
	mem = ft_bitscreate((void*)str, ft_strlen(str));
	ft_bitsmodifbit(mem, 0, 0, 0);
	ft_bitsmodifbit(mem, 0, 1, 1);
	ft_bitsmodifbit(mem, 0, 2, 0);
	ft_bitsmodifbit(mem, 0, 3, 1);
	ft_bitsmodifbit(mem, 0, 4, 0);
	ft_bitsmodifbit(mem, 0, 5, 1);
	ft_bitsmodifbit(mem, 0, 6, 0);
	ft_bitsmodifbit(mem, 0, 7, 0);
	ft_putendl(mem->memory);
	ft_strdel(&str);
	ft_bitsdel(mem);
}
