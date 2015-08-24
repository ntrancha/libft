/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 12:30:16 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:26:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/convert.h"

static int         bintodec(char *str)
{
    int     res;
    int     len;
    int     size;

    len = ft_strlen(str);
    size = len - 1;
    res = 0;
    while (--len >= 0)
        if (str[len] - 48 == 1)
            res += ft_power(2, size - len);
    if (str[size] == '1')
        res++;
    ft_strdel(&str);
    return (res);
}

int		ft_rgb(int red, int green, int blue)
{
	char	*tmp;
	char	*tmp2;
	char	*str;
	int		bin;

	if (red < 0 || red > 255)
		return (0);
	if (green < 0 || green > 255)
		return (0);
	if (blue < 0 || blue > 255)
		return (0);
	tmp = ft_itoa(ft_dectobin(red));
	tmp2 = ft_itoa(ft_dectobin(green));
	str = ft_strjoin(tmp, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	tmp2 = ft_itoa(ft_dectobin(blue));
	tmp = ft_strjoin(str, tmp2);
	bin = bintodec((tmp));
	ft_strdel(&str);
	ft_strdel(&tmp2);
	return (bin);
}
