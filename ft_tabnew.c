/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 05:49:43 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/15 05:49:43 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int	**tabnew(int line, int col)
{
	int		**ptr;
	int		i;

	ptr = malloc(col * sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < col)
	{
		ptr[i] = malloc(line * sizeof(**ptr));
     	if (ptr[i] == NULL)
			return (NULL);
		i++;
	}
	return (ptr);
}

t_tab		*ft_tabnew(int line, int col)
{
	t_tab	*tab;

	if (line < 1 || col < 1)
		return (NULL);
	if ((tab = malloc(sizeof(t_tab))) == NULL)
		return (NULL);
	if ((tab->tab = tabnew(line, col)) == NULL)
		return (NULL);
	tab->col = col;
	tab->line = line;
	ft_tabclear(&tab);
	return (tab);
}
