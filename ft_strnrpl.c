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

static int	next2(t_strnrpl *str, int start, int end, int n)
{
	char	*p1;
	char	*p2;
	char	*tmp;

	p1 = ft_strsub(*(str->str), 0, start);
	if (p1 == NULL)
		RETURN_NULL;
	p2 = ft_strsub(*(str->str), end, ft_strlen(*(str->str)) - end);
	if (p2 == NULL)
		RETURN_NULL;
	tmp = ft_strjoin(p1, str->str3);
	if (tmp == NULL)
		RETURN_NULL;
	if (str->str != NULL)
		ft_strdel(str->str);
	*(str->str) = ft_strjoin(tmp, p2);
	ft_strdel(&tmp);
	ft_strdel(&p1);
	ft_strdel(&p2);
	if (*(str->str) == NULL)
		RETURN_NULL;
	return (n - 1);
}

static int	next(int *start, int c, int i, t_strnrpl *str)
{
	if (str->str2[c] == (*str->str)[i])
	{
		if (*start == -1)
			*start = i;
		c++;
		return (c);
	}
	*start = -1;
	RETURN_FAIL;
}

static int	foreach(t_strnrpl *str, int *n, int *index)
{
	*(str->count) = next(str->start, *(str->count), *index, str);
	if (str->str2[*(str->count)] == '\0' && *(str->count) != -1)
	{
		*n = next2(str, *(str->start), *index + 1, *n);
		ft_strnrpl(str->str, str->str2, str->str3, *n);
		RETURN_FAIL;
	}
	if (*(str->count) == -1)
		*(str->count) = 0;
	(*index)++;
	RETURN_SUCCES;
}

int			ft_strnrpl(char **source, char *search, char *remplace, int n)
{
	int			index;
	int			count;
	int			start;
	t_strnrpl	*strnrpl;

	index = 0;
	count = 0;
	start = -1;
	strnrpl = malloc(sizeof(t_strnrpl));
	strnrpl->str = source;
	strnrpl->str2 = search;
	strnrpl->str3 = remplace;
	strnrpl->start = &start;
	strnrpl->count = &count;
	while ((*(strnrpl->str))[index] != '\0' && n != 0)
		if (foreach(strnrpl, &n, &index) == -1)
			n = 0;
	free(strnrpl);
	return (n);
}
