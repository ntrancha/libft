/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 10:00:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/11 18:19:34 by ntrancha         ###   ########.fr       */
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
	b = ft_octet_shr(a, 1);
    ft_putoctet(b);
	ft_putendl("");
	b = ft_octet_shl(a, 1);
    ft_putoctet(b);
	ft_putendl("");
}

int		main(void)
{
	int	num;

	num = 0;
	while (num++ < 9)
		test(num);
}
