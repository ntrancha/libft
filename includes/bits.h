/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:32:25 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/26 11:08:19 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITS_H
# define BITS_H
# include <stdlib.h>

typedef unsigned char	t_octets;
typedef unsigned char	t_octet;
typedef int				t_bit;

typedef struct			s_bits
{
	t_octets			*memory;
	size_t				octet;
}						t_bits;

t_bits		*ft_bitscreate(void *memory, size_t octet);
t_bits		*ft_bitscreate_empty(size_t octet);
t_bits		*ft_bitsdel(t_bits *memory);
t_bits		*ft_bitscopy(t_bits *memory);
t_octet		ft_bitsgetoctet(t_bits *memory, int octet);
t_octets	*ft_bitsgetaddr(t_bits *memory, int octet);
t_octet		ft_bitssetoctet(t_bits *memory, int n_octet, t_octet octet);
int	    	ft_bitssetbit(t_bits *memory, int octet, int bit, int value);
long long   ft_bitsvalue(t_bits *memory);
t_bits      *ft_bits_add(t_bits *a, t_bits *b, int base);
t_bits      *ft_bits_less(t_bits *a, t_bits *b, int base);
t_bits      *ft_bits_addition(t_bits *a, t_bits *b, int base, int sign);

int			ft_octetvalue(t_octet octet);
int			ft_octetgetbit(t_octet a, int bit);
t_octet		ft_octetsetbit(t_octet a, int bit, int value);
t_octet		ft_octet_or(t_octet a, t_octet b);
t_octet		ft_octet_xor(t_octet a, t_octet b);
t_octet		ft_octet_and(t_octet a, t_octet b);
int         ft_octet_add(t_octet *a, t_octet b);
int         ft_octet_sub(t_octet *a, t_octet b);
t_octet		ft_octet_shr(t_octet a, int shr);
t_octet		ft_octet_shl(t_octet a, int shl);
t_octet		ft_octet_ror(t_octet a, int ror);
t_octet		ft_octet_rol(t_octet a, int rol);
t_octet		ft_octet_not(t_octet a);

#endif
