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

static char		*ft_ftoa_next(float n, int i, char *s, int p)
{
	float	index;
	float	f;
	char	*tmp;
	char	*tmp2;

	index = 100000000;
	f = (n - i) * index;
	if (ft_ftoi(f) > 0)
	{
		ft_straddchar(&s, ',');
		tmp2 = ft_itoa(ft_ftoi(f));
		tmp = ft_strsub(tmp2, 0, p);
		ft_strdel(&tmp2);
		tmp2 = ft_strjoin(s, tmp);
		ft_strdel(&tmp);
		ft_strdel(&s);
		s = ft_strdup(tmp2);
		ft_strdel(&tmp2);
		
	}
	return (s);
}

char   			*ft_ftoa(float n, int p)
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
    if (!(s = (char *) malloc((len + 1) * sizeof(*s))))
        return (NULL);
    if (i < 0)
    {
        s[0] = '-';
        i *= -1;
    }
    s[len] = '\0';
    while (i >= 10)
    {
        s[len-- - 1] = i % 10 + '0';
        i = i / 10;
    }
    s[len - 1] = i + '0';
    return (ft_ftoa_next(n, in, s, p));
}
