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
#include "includes/libft.h"
#define	MAX_FTOA	1000000


static char     *ft_ftoa_down(float r, char *s)
{
	int		test;

	test = 0;
	while (ft_atof(s) > r && test++ < 100)
		if (s[ft_strlen(s) - 1] == '0')
		{
			s[ft_strlen(s) - 1] = '9';
			if (s[ft_strlen(s) - 2] == '0')
			{
				s[ft_strlen(s) - 2] = '9';
				s[ft_strlen(s) - 3] -= 1;			
			}
			else
				s[ft_strlen(s) - 2] -= 1;
		}
		else
			s[ft_strlen(s) - 1] -= 1;
	return (s);
}

static char     *ft_ftoa_up(float r, char *s)
{
	int		test;

	test = 0;
	if (ft_atof(s) > r)
		return (ft_ftoa_down(r, s));
	while (ft_atof(s) < r && test++ < 100)
		if (s[ft_strlen(s) - 1] == '9')
		{
			s[ft_strlen(s) - 1] = '0';
			if (s[ft_strlen(s) - 2] == '9')
			{
				s[ft_strlen(s) - 2] = '0';
				s[ft_strlen(s) - 3] += 1;			
			}
			else
				s[ft_strlen(s) - 2] += 1;
		}
		else
			s[ft_strlen(s) - 1] = s[ft_strlen(s) - 1] + 1;
	return (s);
}

static char		*ft_ftoa_zero(char *s)
{
	char		*tmp;
	char		*tmp2;

	tmp = ft_strdup(".000000");
	tmp2 = ft_strjoin(s, tmp);
	ft_strdel(&s);
	s = ft_strdup(tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (s);
}

static char		*ft_ftoa_next(float n, int i, char *s)
{
	float	index;
	float	f;
	float	r;
	int		p;

	index = MAX_FTOA;
	r = n;
	p = ft_ftoi(n);
	f = (n * MAX_FTOA * 10) - (i * MAX_FTOA* 10);
	if (ft_ftoi(f) > 0)
	{
		ft_straddchar(&s, '.');
		while (index > 1)
		{
			n = f / index;
			p = ft_ftoi(n);
			f = f - (p * index);
			ft_straddchar(&s, (p + '0'));
			index /= 10;
		}
	}
	else
		return (ft_ftoa_zero(s));	
	return (ft_ftoa_up(r, s));
}

char   			*ft_ftoa(float n)
{   
    char    	*s;
    size_t  	len;
	int			i;
	int			in;
    
    if (n == 0)
        return (ft_strdup("0"));
	i = ft_ftoi(n);
	in = i;
    len = ft_nbrlen(i);
    if (i < 1)
		if (!(s = ft_strdup("0")))
			return (NULL);
		else
	        return (ft_ftoa_next(n, in, s));
    if (!(s = (char *) malloc((len + 1) * sizeof(*s))))
        return (NULL);
    s[len] = '\0';
    while (i >= 10)
    {
        s[len-- - 1] = i % 10 + '0';
        i = i / 10;
    }
    s[len - 1] = i + '0';
    return (ft_ftoa_next(n, in, s));
}
