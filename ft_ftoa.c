/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 21:14:37 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/26 21:14:37 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "includes/libft.h"
#define	MAX_FTOA	10000000

static char		*ft_ftoa_cut(float n, char *s)
{
	int			index;
	int			i;

	if (ft_strlen(s) - ft_nbrlen(ft_ftoi(n)) > 6)
		s[ft_strlen(s) - 1] = '\0';
	while (n > ft_atof(s))
		s[ft_strlen(s) - 1] += 1;
	while (n < ft_atof(s))
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

static char		*ft_ftoa_next(float n, char *s)
{
	int		f;
	int		p;
	char	*str;
	char	*tmp;

	ft_straddchar(&s, '.');
	p = ft_ftoi((n - ft_ftoi(n)) * MAX_FTOA);
	if (p == 0)
		return (ft_ftoa_cut(n, s));
	f = ft_nbrlen(p);
	while (f++ < 7)
        ft_straddchar(&s, '0');
	str = ft_itoa(p);
	tmp = ft_strjoin(s, str);
	ft_strdel(&s);
	s = ft_strdup(tmp);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (ft_ftoa_cut(n, s));
}

char   			*ft_ftoa(float n)
{   
    char    	*s;

    if (n == 0)
        return (ft_strdup("0"));
    if (n < 1)
		return (ft_ftoa_next(n, ft_strdup("0")));
	s = ft_itoa(ft_ftoi(n));
	if (s == NULL)
		return (NULL);
	return (ft_ftoa_next(n, s));
}
