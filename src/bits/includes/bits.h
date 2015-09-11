/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:32:25 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/11 09:12:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITS_H
# define BITS_H

typedef unsigned char	t_bin;
typedef unsigned char	t_octet;
typedef _Bool			t_bit;

typedef struct			s_bits
{
	t_octet				*memory;
	size_t				octet;
}						t_bits;

t_bits	*ft_bitscreate(void *memory, size_t octet);
t_bits	*ft_bitsdel(t_bits *memory);
t_octet	ft_bitsgetoctet(t_bits *memory, int octet);
t_octet	*ft_bitsgetaddr(t_bits *memory, int octet);
t_octet ft_bits_or(t_octet a, t_octet b);
t_octet ft_bits_xor(t_octet a, t_octet b);
t_octet ft_bits_and(t_octet a, t_octet b);
t_octet ft_bits_shr(t_octet a, int shr);
t_octet ft_bits_shl(t_octet a, int shl);
t_octet ft_bits_ror(t_octet a, int ror);
t_octet ft_bits_rol(t_octet a, int rol);
t_octet ft_bits_not(t_octet a);
t_octet ft_bitssetoctet(t_bits *memory, int n_octet, t_bin octet);
int	    ft_bitssetbit(t_bits *memory, int octet, int bit, int value);

#endif
