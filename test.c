/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 10:00:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/26 11:58:05 by ntrancha         ###   ########.fr       */
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

void	prime(void)
{
	int	num;
	int count;

	num = 0;
	while (++num < 1000000)
		if (ft_is_prime(num))
		{
			ft_putnbr(count);
			ft_putstr(" : ");
			ft_putnbr_endl(num);
			count++;
		}
}

void	testa(void)
{
	t_bag *bag;

	bag = ft_bag_create();
	ft_bag_addvar(bag, ft_strdup("NK"), "name");
	ft_bag_addvar(bag, ft_strdup("test"), "1");
	ft_bag_addvar(bag, ft_strdup("NULL"), "2");
	ft_putstr((char*)ft_bag_get(bag, "1"));
    ft_putendl(ft_addstr("11", "-1"));
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
    t_bits *mem3;
	void	(*del)(void**);
    unsigned char c;
    char *c2;
    char *c1;

    c2 = ft_strdup("013");
    c1 = ft_strdup("14");
    mem = ft_sinttooct(c2);
	//ft_putbits(mem, '-');
    mem2 = ft_sinttooct(c1);
    mem3  = ft_bits_addition(mem, mem2, 10, 1);
	//ft_putbits(mem3, '-');
    ft_bitsdel(mem);
    ft_strdel(&c2);
    ft_bitsdel(mem2);
    ft_strdel(&c1);
    //ft_bitsdel(mem3);
	return 1;
    c = 254;
    num = ft_octet_add(&c, 2);
    ft_putnbr_endl(num);
    ft_putnbr_endl((int)c);
    c2 = ft_strdup("-01234");
    c2[0] -= 48;
    c2[1] -= 48;
    c2[2] -= 48;
    c2[3] -= 48;
    c2[4] -= 48;
    mem = ft_bitscreate((void*)c2, 5);
	ft_putbits(mem, '-');
    ft_bitsdel(mem);
	//testa();
	return 1;
	prime();
	del= &ft_memdel;
    str = ft_strdup("4");
	ft_putaddr((void*)str);
    str2 = ft_strdup("9");
	ft_putaddr((void*)str2);
    ft_putendl("");
    ft_putendl(ft_addsubstr(str, str2, -1));
    ft_strdel(&str);
    ft_strdel(&str2);
	ft_puthexa("coucou les enfants", ' ');
	num = 42;
    mem = ft_bitscreate((void*)&num, sizeof(int));
	ft_putbits(mem, '-');
    ft_bitsdel(mem);
	num = ft_octet_rol(num, 1);
    mem = ft_bitscreate((void*)&num, sizeof(int));
	ft_putbits(mem, '\0');
    ft_bitsdel(mem);
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
