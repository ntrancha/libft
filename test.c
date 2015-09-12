/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 10:00:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/12 08:42:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		test(int num)
{
	t_octet a;
	t_octet b;

	ft_putnbr_endl(num);
	a = (t_octet) num;
    ft_putoctet(a);
	ft_putendl("");
	b = ft_octet_ror(a, 4);
    ft_putoctet(b);
	ft_putendl("");
	b = ft_octet_rol(a, 4);
    ft_putoctet(b);
	ft_putendl("");
}

int		main(void)
{
	int	num;
    char *str;
    long test;
    t_bits *mem;

    str = ft_strdup("test");
    ft_putnbr_endl(sizeof(int));
    ft_putnbr_endl(sizeof(long long));
    test = 87198236714123;
	num = 2123123123;
    mem = ft_bitscreate((void*)&num, sizeof(int));
    ft_bitsvalue(mem);
    ft_bitsdel(mem);
	//while (num++ < 9)
		//test(num);
}
