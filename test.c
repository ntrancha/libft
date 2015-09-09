/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 10:00:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/09 03:07:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

typedef unsigned char	t_bin;
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


int			ft_strisoctet(char *str)
{
	int		index;
	int		test;
	int		size;

	index = -1;
	size = 0;
	while (str && str[++index] && size < 9)
		if (str[index] == '0' || str[index] == '1')
			size++;
		else
			return (0);
	if (size != 8)
		return (0);
	return (1);
}

int			ft_bitssetbit(t_mem *memory, int octet, int bit, int value)
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

t_octet		ft_bitssetoctet(t_mem *memory, int n_octet, t_octet octet)
{
	
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
	ft_putendl(mem->memory);
	ft_strdel(&str);
	ft_bitsdel(mem);
}
