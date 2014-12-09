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

#include <libft.h>
#include <stdlib.h>

static void	*end(char **source, char *remplace, int start, int end)
{
	char	*p1;
	char	*p2;
	char	*tmp;

	p1 = ft_strsub(*source, 0, start);
	if (p1 == NULL)
		return (NULL);
	p2 = ft_strsub(*source, end, ft_strlen(*source) - end);
	if (p2 == NULL)
		return (NULL);
	tmp = ft_strjoin(p1, remplace);
	if (tmp == NULL)
		return (NULL);
	ft_strdel(source);
	*source = ft_strjoin(tmp, p2);
	ft_strdel(&tmp);
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
			ft_strnrpl_trans(source, remplace, start, index + 1);
			n--;
			return (ft_strnrpl(source, search, remplace, n));
		}
		index++;
	}
	return (n);
}
