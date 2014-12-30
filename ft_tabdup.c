/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 21:35:45 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/29 21:35:45 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_tab		*ft_tabdup(t_tab *tab)
{
	t_tab	*new;
	int		col;
	int		line;

	if (!tab)
		return (NULL);
	if (!(new = ft_tabnew(tab->line, tab->col)))
		return (NULL);
	col = 0;
	while (col < tab->col)
    {
        line = 0;
        while (line < tab->line)
        {
			new->tab[col][line] = tab->tab[col][line];
			line++;
        }
        col++;
    }
	return (new);
}
