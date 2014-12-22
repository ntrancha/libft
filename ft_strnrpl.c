/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrpl.c	    								:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:31:34 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/09 12:31:34 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int	next2(t_doublestr *str, int start, int end, int n)
{
	char	*p1;
	char	*p2;
	char	*tmp;

	p1 = ft_strsub(*(str->str), 0, start);
	if (p1 == NULL)
		return (0);
	p2 = ft_strsub(*(str->str), end, ft_strlen(*(str->str)) - end);
	if (p2 == NULL)
		return (0);
	tmp = ft_strjoin(p1, str->str3);
	if (tmp == NULL)
		return (0);
	if (str->str != NULL)
		ft_strdel(str->str);
	*(str->str) = ft_strjoin(tmp, p2);
	ft_strdel(&tmp);
	ft_strdel(&p1);
	ft_strdel(&p2);
	if (*(str->str) == NULL)
		return (0);
	return (n - 1);
}

static int	next(int *start, int c, int i, t_doublestr *str)
{
	if (str->str2[c] == (*str->str)[i])
	{
		if (*start == -1)
			*start = i;
		c++;
		return (c);
	}
	*start = -1;
	return (-1);
}

static int	foreach(t_doublestr *str, int *n, int *index)
{
	*(str->count) = next(str->start, *(str->count), *index, str);
	if (str->str2[*(str->count)] == '\0' && *(str->count) != -1)
	{
		*n = next2(str, *(str->start), *index + 1, *n);
		ft_strnrpl(str->str, str->str2, str->str3, *n);
		return (-1);
	}
	if (*(str->count) == -1)
		*(str->count) = 0;
	(*index)++;
	return (1);
}

int			ft_strnrpl(char **source, char *search, char *remplace, int n)
{
	int			index;
	int			count;
	int			start;
	t_doublestr	*doublestr;

	index = 0;
	count = 0;
	start = -1;
	doublestr = malloc(sizeof(t_doublestr));
	doublestr->str = source;
	doublestr->str2 = search;
	doublestr->str3 = remplace;
	doublestr->start = &start;
	doublestr->count = &count;
	while ((*(doublestr->str))[index] != '\0' && n != 0)
	{
		if (foreach(doublestr, &n, &index) == -1)
			n = 0;
	}
	free(doublestr);
	return (n);
}
