/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:31:54 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/30 19:31:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_listtostr(t_list *list)
{
	t_node	*node;
	int		count;
	int		index;
	char	*str;
	char	*tmp;

	if (!list)
		return (NULL);
	if (!(str = ft_strnew(ft_liststrlen(list) + 1)))
		return (NULL);
	count = 0;
	while (node)
	{
		index = 0;
		tmp = (char*)node->content;
		while (tmp[index])
			str[count++] = tmp[index++];
		node = node->next;
	}
	return (str);
}
