/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 09:18:06 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/27 08:13:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int			ft_strsplit_count(char *s, char c)
{
	int				count;

	count = 1;
	while (*s)
	{
		if (*s == c && *s + 1 != c)
			count++;
		s++;
	}
	return (count);
}

static	int			ft_strsplit_test(char *s, char c)
{
	int				count;

	count = 0;
	while (s[count])
	{
		if (s[count] != c)
			return (0);
		count++;
	}
	return (1 + count);
}

static char			*ft_strsplit_clean(char const *s, char c)
{
	char			*tmp;
	int				size;
	int				start;
	int				end;

	tmp = ft_strdup((char*)s);
	start = 0;
	end = -1;
	size = 0;
	while (tmp[size])
	{
		if (end == -1 && tmp[size] == c)
			start++;
		else if (end == -1)
			end = 0;
		size++;
	}
	while (size)
		if (tmp[--size] == c)
			end++;
		else
			size = 0;
	size = ft_strlen(tmp);
	tmp = ft_strsub(tmp, start, size - end - start);
	return (tmp);
}

static char			**ft_strsplit_cut(char *clean, char c, int mark)
{
	char			**ret;
	int				count;
	int				start;
	int				end;

	count = 0;
	ret = malloc(sizeof(char*) * count + 1);
	start = 0;
	end = 0;
	while (clean[count])
	{
		if (clean[count] == c && clean[count + 1] != c)
		{
			ret[mark] = ft_strsub(clean, start, end - start);
			ret[mark] = ft_strsplit_clean(ret[mark], c);
			mark++;
			start = end + 1;
		}
		end++;
		count++;
	}
	ret[mark++] = ft_strsub(clean, start, end - start);
	ret[mark] = 0;
	return (ret);
}

char				**ft_strsplit(char const *s, char c)
{
	char			*clean;
	char			**ret;
	int				count;
	int				mark;

	mark = 0;
	count = ft_strsplit_test((char*)s, c);
	if (!s || !s[0] || count)
	{
		ret = malloc(sizeof(char *) * 2);
		ret[0] = (char*)s;
		ret[1] = 0;
		return (ret);
	}
	count = ft_strsplit_count((char*)s, c);
	if (s && s[0])
	{
		clean = ft_strsplit_clean(s, c);
		ret = ft_strsplit_cut(clean, c, mark);
		if (!ret)
			return (NULL);
	}
	else
		return (NULL);
	return (ret);
}
