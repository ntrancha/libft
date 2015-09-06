/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 11:25:33 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/06 06:43:47 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	dectohex(int num, int size, char *tmp)
{
	if ((num % 16) < 10)
		tmp[size] = (num % 16) + 48;
	else
		tmp[size] = (num % 16) + 55;
	return (num / 16);
}

static void	dectohex_next(int num, int size, char *tmp)
{
	if (num < 10)
		tmp[size] = num + 48;
	else
		tmp[size] = num + 55;
	while (size--)
		tmp[size] = '0';
}

char		*ft_dectohex(int num)
{
	char	*tmp;
	char	*ret;
	int		size;
	int		neg;

	if (num == 0)
		return (ft_strdup("0"));
	size = ft_nbrlen(num);
	tmp = ft_strnew(size + 1);
	neg = (num < 0) ? 1 : 0;
	num = ft_abs(num);
	while (num > 16 && size > 0)
		num = dectohex(num, size--, tmp);
	dectohex_next(num, size, tmp);
	ret = ft_strcleanfront(tmp, '0');
	ft_strdel(&tmp);
	if (neg)
		tmp = ft_strjoin("-", ret);
	else
		tmp = ft_strdup(ret);
	ft_strdel(&ret);
	return (tmp);
}
