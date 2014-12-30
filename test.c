/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 21:49:08 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/29 21:49:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	main(void)
{
	t_list	*list;
	t_list	*list2;
	char	*str;
	char	*str2;
	char	*str3;
	void	(*p_fonction)(void**);

	p_fonction = ft_memdel;
	str = ft_strdup("coucou");
	list = ft_listadd(NULL, str);
	str2 = ft_strdup("ok");
	list = ft_listadd(list, str2);
	str3 = ft_strdup("ok3");
	list = ft_listadd(list, str3);
	ft_listswap(list, list->start, list->start->next);
	ft_listswap(list, list->start->next->next, list->start->next);
	ft_putendl(list->start->content);
	ft_putendl(list->start->next->content);
	ft_putendl(list->start->next->next->content);
	ft_listdel(list, p_fonction);
}
