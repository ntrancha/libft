/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 10:00:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/12 11:52:14 by ntrancha         ###   ########.fr       */
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
    char *str2;
    long test;
	long long a;
    t_bits *mem;
    t_bits *mem2;

    str = ft_strdup("95");
    str2 = ft_strdup("26");
    ft_putendl(ft_substr(str, str2));
    return (-1);
    ft_putnbr_endl(sizeof(int));
    ft_putnbr_endl(sizeof(long long));
    test = 87198236714123;
	num = 2123123123;
    mem = ft_bitscreate((void*)&num, sizeof(int));
    a = ft_bitsvalue(mem);
    mem2 = ft_bitscreate((void*)&a, sizeof(long long));
	ft_putendl("");
    a = ft_bitsvalue(mem2);
    ft_strdel(&str);
    ft_bitsdel(mem);
    ft_bitsdel(mem2);
}
