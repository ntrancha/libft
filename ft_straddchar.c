/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 05:54:23 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/15 05:54:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

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
	tmp2 = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	while (tmp[++index])
		tmp2[index] = tmp[index];
	tmp2[index] = c;
	tmp2[index + 1] = '\0';
	*str = ft_strdup(tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}
