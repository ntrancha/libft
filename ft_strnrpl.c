/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrpl.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:31:34 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/09 12:31:34 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int	next2(char **source, char *remplace, int start, int end, int n)
{
	char	*p1;
	char	*p2;
	char	*tmp;

	p1 = ft_strsub(*source, 0, start);
	if (p1 == NULL)
		return (0);
	p2 = ft_strsub(*source, end, ft_strlen(*source) - end);
	if (p2 == NULL)
		return (0);
	tmp = ft_strjoin(p1, remplace);
	if (tmp == NULL)
		return (0);
	ft_strdel(source);
	*source = ft_strjoin(tmp, p2);
	ft_strdel(&tmp);
	if (*source == NULL)
		return (0);
	return (n);
}

static int	next(int *start, int c, int i, char *search, char **source)
{
	if (search[c] == (*source)[i])
	{
		if (*start == -1)
			*start = i;
		c++;
		return (c);
	}
	*start = -1;
	return (0);
}

int			ft_strnrpl(char **source, char *search, char *remplace, int n)
{
	int		index;
	int		count;
	int		start;

	index = 0;
	count = 0;
	start = -1;
	while ((*source)[index] != '\0' && n > 0)
	{
		count = next(&start, count, index, search, source);
		if (search[count] == '\0')
		{
			n = next2(source, remplace, start, index + 1, n);
			return (ft_strnrpl(source, search, remplace, n));
		}
		index++;
	}
	return (n);
}
