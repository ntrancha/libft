/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 09:18:06 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 23:02:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/mem.h"

static char			**strsplit(char *s, char c, int nbr)
{
	char			**ret;
	int				index;
	int				start;
	int				count;

	start = 0;
	index = 0;
	count = 0;
	if (!(ret = ft_memalloc(sizeof(char*) * nbr * 2)))
		return (NULL);
	while (s[index])
	{
		if (s[index] == c)
		{
			if (!(ret[count] = ft_strsub(s, start, index - start)))
				return (NULL);
			count++;
			start = index + 1;
		}
		index++;
	}
	ret[count] = ft_strsub(s, start, index - start);
	ret[count + 1] = NULL;
	return (ret);
}

static char			*cleanstr(char const *s, char c)
{
	char			*str;
	int				index;
	int				end;

	index = 0;
	while (s[index] == c)
		index++;
	end = ft_strlen((char*)s) - 1;
	while (s[end] == c)
		end--;
	str = ft_strsub(s, index, end - index + 1);
	return (str);
}

static int			countchar(char *str, char c)
{
	int 			ret;
	int				index;

	ret = 1;
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			ret++;
		index++;
	}
	return (ret);
}

char				**ft_strsplit(char const *s, char c)
{
	char			*str;
	char			**ret;
	int				nbr;

	if (s == NULL)
	{
		ret = ft_memalloc(sizeof(char *) * 2);
		ret[0] = NULL;
		return (ret);
	}
	str = cleanstr(s, c);
	ft_strdoublon(&str, c);
	if (!str)
	{
		ret = ft_memalloc(sizeof(char) * 2);
		ret[0] = NULL;
		return (ret);
	}
	nbr = countchar((char*)s, c);
	ret = strsplit((char*)str, c, nbr);
	ft_strdel(&str);
	return (ret);
}
