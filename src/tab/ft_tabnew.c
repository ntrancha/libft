/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 05:49:43 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:45:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/mem.h"

static int	**tabnew(int line, int col)
{
	int		**ptr;
	int		i;

	ptr = ft_memalloc(col * sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < col)
	{
		ptr[i] = ft_memalloc(line * sizeof(**ptr));
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
	if ((tab = ft_memalloc(sizeof(t_tab))) == NULL)
		return (NULL);
	if ((tab->tab = tabnew(line, col)) == NULL)
		return (NULL);
	tab->col = col;
	tab->line = line;
	ft_tabclear(&tab);
	return (tab);
}
