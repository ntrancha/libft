/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 05:54:23 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:48:07 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"
#include "../../includes/strings.h"

void		ft_straddchar(char **str, char c)
{
	char	*tmp;
	char	*tmp2;
	int		index;

	index = -1;
	if (*str)
		tmp = ft_strdup(*str);
	else
		tmp = ft_strdup("");
	ft_strdel(str);
	tmp2 = ft_memalloc(sizeof(char) * (ft_strlen(tmp) + 2));
	while (tmp[++index])
		tmp2[index] = tmp[index];
	tmp2[index] = c;
	tmp2[index + 1] = '\0';
	*str = ft_strdup(tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}
