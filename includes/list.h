/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:25:24 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 12:59:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include "list.h"

typedef struct		s_lst
{
	void			*content;
	size_t			content_size;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

typedef struct		s_list
{
	t_node			*start;
	t_node			*end;
	int				size;
}					t_list;

t_list	*ft_listadd(t_list *list, void *content);
t_list	*ft_listaddfirst(t_list *list, void *content);
t_list	*ft_listaddafter(t_list *list, t_node *prev, void *content);
t_list	*ft_listcreate(void);
char	*ft_listtostr(t_list *list);
char	*ft_listtostrd(t_list *list, char *del);
int		ft_listcontent(t_list *list, t_node *node);
void	ft_listdel(t_list *list, void (del)(void **));
void	ft_listdelnode(t_list *list, t_node *node, void (del)(void **));
t_node	*ft_listdelnoden(t_list *list, t_node *node, void (del)(void **));
size_t	ft_listlen(t_list *list);
size_t	ft_liststrlen(t_list *list);
size_t	ft_liststrlenmax(t_list *list);
t_list	*ft_listreverse(t_list *list);
void	ft_listswap(t_list *list, t_node *node, t_node *node2);
void	ft_listputstr(t_list *list, void (put)(char const *));
int		ft_gnl_list(int const fd, char **line);
void	ft_lstdel(t_lst **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_lst **alst, void (*del)(void *, size_t));
t_lst	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstadd(t_lst **alst, t_lst *new);
t_lst	*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem));
void	ft_lstiter(t_lst *lst, void (*f)(t_lst *elem));

#endif
