/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:40:56 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/11 11:30:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int		ft_itoa_next(int n)
{
	int			tmp;
	int			ret;

	tmp = n;
	ret = 0;
	if (n < 0 || !n)
		ret++;
	while (tmp)
	{
		ret++;
		tmp /= 10;
	}
	return (ret);
}

static char		*ft_itoa_end(void)
{
	char		*new;

	new = malloc(sizeof(char) * 12);
	new = ft_strcpy(new, "-2147483648");
	return (new);
}

char			*ft_itoa(int n)
{
	char		*ret;
	int			neg;
	int			num;
	int			tmp;
	int			tmp2;

	neg = 0;
	if (n < 0)
		neg = 1;
	num = ft_itoa_next(n);
	tmp2 = ((n < 0) ? -n : n);
	ret = ft_strnew(num + 2);
	if (!tmp2)
		ret[0] = '0';
	else if (neg)
		ret[0] = '-';
	tmp = num - 1;
	while (tmp2)
	{
		ret[tmp--] = '0' + tmp2 % 10;
		tmp2 /= 10;
	}
	if (ret[num - 1] == '(')
		return (ft_itoa_end());
	return (ret);
}
