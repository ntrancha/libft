/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 10:00:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/11 11:31:20 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		test(int num)
{
	t_octet a;
	t_octet b;
	char	*bin;

	ft_putnbr_endl(num);
	a = (t_octet) num;
	bin = ft_itoa(ft_dectobin(a));
	ft_putendl(bin);
	ft_strdel(&bin);
	b = ft_octet_ror(a, 1);
	bin = ft_itoa(ft_dectobin(b));
	ft_putendl(bin);
	ft_strdel(&bin);
}

int		main(void)
{
	int	num;

	num = 0;
	while (num++ < 12)
		test(num);
}
