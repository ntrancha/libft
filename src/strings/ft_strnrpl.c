/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrpl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 11:21:59 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 23:00:38 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

static int	find_first(char *str, char *search)
{
	int		ret;
	int		index;
	char	c_str;
	char	c_search;

	ret = 0;
	while (str[ret])
	{
		index = 0;
		c_str = str[ret + index];
		c_search = search[index];
		while (c_str && c_search && c_str == c_search)
		{
			c_str = str[ret + index];
			c_search = search[index++];
		}
		if (c_search == '\0')
			return (ret);
		ret++;
	}
	return (0);
}

int			ft_strnrpl(char **str, char *search, char *remplace, int max)
{
	char	*tmp;
	char	*part_one;
	char	*part_two;
	int		start;
	int		size;

	if (!str || !(*str) || !search || !remplace || max-- == 0)
		return (0);
	start = find_first(*str, search);
	if (start == 0)
		return (0);
    part_one = ft_strsub(*str, 0, start);
    size = start + ft_strlen(search);
    part_two = ft_strsub(*str, size, ft_strlen(*str) - size);
    tmp = ft_strjoin(part_one, remplace);
    ft_strdel(&part_one);
    part_one = ft_strjoin(tmp, part_two);
    ft_strdel(&part_two);
    ft_strdel(&tmp);
    ft_strdel(str);
    *str = ft_strdup(part_one);
    ft_strdel(&part_one);
	return (ft_strnrpl(str, search, remplace, max));
}
