/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 06:52:30 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:36:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/macros.h"

static void	list_swap(t_list *list, t_node *node, t_node *node2)
{
	if (list->start == node)
		list->start = node2;
	else if (list->start == node2)
		list->start = node;
	if (list->end == node)
		list->end = node2;
	else if (list->end == node2)
		list->end = node;
}

static void	listswapnode2(t_list *list, t_node *node)
{
	t_node	*prev2;
	t_node	*next3;
	t_node	*tmp3;

	if (list && node && node->next)
	{
		tmp3 = node->next;
		prev2 = node->previous;
		next3 = tmp3->next;
		if (node->previous)
			node->previous->next = tmp3;
		else
			list->start = tmp3;
		if (tmp3->next)
			tmp3->next->previous = node;
		else
			list->end = node;
		node->previous = tmp3;
		tmp3->next = node;
		tmp3->previous = prev2;
		node->next = next3;
	}
}

static void	listswapnode(t_list *list, t_node *node, t_node *node2)
{
	t_node	*node1prev;
	t_node	*node1next;
	t_node	*node2prev;
	t_node	*node2next;

	node1prev = node->previous;
	node1next = node->next;
	node2prev = node2->previous;
	node2next = node2->next;
	node->next = node2next;
	node->previous = node2prev;
	node2->next = node1next;
	node2->previous = node1prev;
	if (node1prev)
		node1prev->next = node2;
	if (node1next)
		node1next->previous = node2;
	if (node2prev)
		node2prev->next = node;
	if (node2next)
		node2next->previous = node;
	list_swap(list, node, node2);
}

void		ft_listswap(t_list *list, t_node *node, t_node *node2)
{
	if (list && node && node2 && CONTENT(list, node) && CONTENT(list, node2))
	{
		if (node->next == node2)
			listswapnode2(list, node);
		else if (node->previous == node2)
			listswapnode2(list, node2);
		else
			listswapnode(list, node, node2);
	}
}
