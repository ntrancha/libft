/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 20:08:58 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:01:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/count.h"
#include "../../includes/convert.h"
#include "../../includes/macros.h"

static char		*ft_dtoa_cut(double n, char *s)
{
	int			index;
	int			i;

	if (ft_strlen(s) - ft_nbrlen(ft_dtoi(n)) > 6)
		s[ft_strlen(s) - 1] = '\0';
	while (n > ft_atod(s))
		s[ft_strlen(s) - 1] += 1;
	while (n < ft_atod(s))
		s[ft_strlen(s) - 1] -= 1;
	index = 0;
	while (s[index] && s[index] != '.')
		index++;
	i = 0;
	while (s[i + index])
		i++;
	while (i++ <= 6)
		ft_straddchar(&s, '0');
	return (s);
}

static char		*ft_dtoa_next(double n, char *s)
{
	int			f;
	int			p;
	char		*str;
	char		*tmp;

	ft_straddchar(&s, '.');
	p = ft_dtoi((n - ft_dtoi(n)) * MAX_DTOA);
	if (p == 0)
		return (ft_dtoa_cut(n, s));
	f = ft_nbrlen(p);
	while (f++ < 7)
		ft_straddchar(&s, '0');
	str = ft_itoa(p);
	tmp = ft_strjoin(s, str);
	ft_strdel(&s);
	s = ft_strdup(tmp);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (ft_dtoa_cut(n, s));
}

char			*ft_dtoa(double n)
{
	char		*s;

	if (n == 0)
		return (ft_strdup("0"));
	if (n < 1)
		return (ft_dtoa_next(n, ft_strdup("0")));
	s = ft_itoa(ft_dtoi(n));
	if (s == NULL)
		return (NULL);
	return (ft_dtoa_next(n, s));
}
