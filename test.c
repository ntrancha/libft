/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 10:00:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/09 05:06:49 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

typedef unsigned char	t_bin;
typedef unsigned char	t_octet;
typedef _Bool			t_bit;

typedef struct			s_bits
{
	t_octet				*memory;
	size_t				octet;
}						t_bits;

t_bits					*ft_bitscreate(void *memory, size_t octet);
t_bits					*ft_bitsdel(t_bits *memory);
t_octet					ft_bitsgetoctet(t_bits *memory, int octet);
t_octet					*ft_bitsgetaddr(t_bits *memory, int octet);

int			ft_bitssetbit(t_bits *memory, int octet, int bit, int value)
{
	if (ft_bitsgetoctet(memory, octet) == 0 || bit > 7)
		return (-1);
	if (value == 0)
		memory->memory[octet] &= ~(1 << bit);
	else
		memory->memory[octet] |= (1 << bit);
	return (value);
}

t_octet		*ft_bitsgetaddr(t_bits *memory, int octet)
{
	if (octet < ft_strlen(memory->memory))
		return (&memory->memory[octet]);
	return (0);
}

t_octet		ft_bitssetoctet(t_bits *memory, int n_octet, t_bin octet)
{
    t_bin   ret;

    if (!memory || !memory->memory || !memory->memory[n_octet])
        return (0);
    ret = memory->memory[n_octet];
    memory->memory[n_octet] = octet;
    return (ret);
}

t_octet		ft_bitsgetoctet(t_bits *memory, int octet)
{
	if (octet < ft_strlen(memory->memory))
		return (memory->memory[octet]);
	return (0);
}

t_bits		*ft_bitscreate(void *memory, size_t octet)
{
	t_bits	*mem;

	mem = ft_memalloc(sizeof(t_bits));
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

t_bits		*ft_bitsdel(t_bits *memory)
{
	ft_memdel((void*)&(memory->memory));
	ft_memdel((void*)&memory);
	return (NULL);
}

int		main(void)
{
	t_bits	*mem;
	char	*str;
	size_t	size;

	str = ft_strdup("Nk42");
	size = sizeof(str);
	mem = ft_bitscreate((void*)str, ft_strlen(str));
    ft_bitssetoctet(mem, 0, ft_sbintocdec("111000"));
    ft_bitssetoctet(mem, 1, 'a');
    ft_bitssetoctet(mem, 2, 'a');
	ft_putendl(mem->memory);
	ft_strdel(&str);
	ft_bitsdel(mem);
}
