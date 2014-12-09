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

void		*ft_strnrpl_trans(char **source, char *remplace, int start, int end)
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

int			ft_strnrpl(char **source, char *search, char *remplace, int n)
{
	int		index;
	int		count;
	int		start;
	int		end;

	index = 0;
	count = 0;
	start = -1;
	end = 0;
	while ((*source)[index] != '\0' && n > 0)
	{
		if (search[count] == (*source)[index])
		{
			if (start == -1)
				start = index;
			count++;
		}
		else
		{
			count = 0;
		}
		if (search[count] == '\0')
		{
			end = index + 1;
			ft_strnrpl_trans(source, remplace, start, end);
			n--;
			return (ft_strnrpl(source, search, remplace, n));
		}
		index++;
	}
	return (n);
}
